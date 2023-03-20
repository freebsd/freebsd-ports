--- src/readstat_bits.c.orig	2023-03-16 22:38:26 UTC
+++ src/readstat_bits.c
@@ -8,7 +8,7 @@
 
 #include "readstat_bits.h"
 
-int machine_is_little_endian() {
+int machine_is_little_endian(void) {
     int test_byte_order = 1;
     return ((char *)&test_byte_order)[0];
 }
