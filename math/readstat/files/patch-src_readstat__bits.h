--- src/readstat_bits.h.orig	2023-02-19 12:35:46 UTC
+++ src/readstat_bits.h
@@ -7,7 +7,7 @@
 #undef READSTAT_MACHINE_IS_TWOS_COMPLEMENT
 #define READSTAT_MACHINE_IS_TWOS_COMPLEMENT 0
 
-int machine_is_little_endian();
+int machine_is_little_endian(void);
 
 char ones_to_twos_complement1(char num);
 int16_t ones_to_twos_complement2(int16_t num);
