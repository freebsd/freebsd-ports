/^#include <linux\/dvb\/frontend.h>/i\
#include <stdint.h>
s/^#include <linux\/types.h>/#include <stdint.h>/
s/__u8/uint8_t/
s/__u16/uint16_t/
s/__u32/uint32_t/
