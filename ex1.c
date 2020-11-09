#include <stdio.h>
#include "ex1.h"

int is_big_endian(){
    unsigned long x = 1;
    unsigned char* i = (unsigned char*)&x;
    if(*i == 1) {
        return 0;
    }
    return 1;
}

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long mask = 1;
    unsigned long z = 0;
    unsigned char* c;
    int size  = sizeof(long) * 8;
    for (int i = 0; i < size; i++) {
        if (i < size / 2 && mask & y)
            z |= mask;
        else if (i >= size / 2 && mask & x)
            z |= mask;
        mask <<= (unsigned) 1;
    }
    return z;
}

unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    int w = sizeof(x) * 8;
    unsigned char* c = (unsigned char*)&x;
    c += (w/8) - i - 1;
    *c = b;
    return x;
}