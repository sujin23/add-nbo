#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <arpa/inet.h>

uint32_t read_nbo(const char *filename) {
    FILE *file = fopen(filename, "rb"); 

    uint32_t number;
    fread(&number, sizeof(uint32_t), 1, file);
    fclose(file);

    return ntohl(number);
}

void add_nbo(const char *first_file, const char *second_file) {
    uint32_t a = read_nbo(first_file);
    uint32_t b = read_nbo(second_file);
    uint32_t sum = a + b;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", a, a, b, b, sum, sum);
}

int main(int argc, char *argv[]) {

    add_nbo(argv[1], argv[2]);

    return 0;
}

