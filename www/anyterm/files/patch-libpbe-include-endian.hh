--- libpbe/include/endian.hh.orig	2014-08-15 14:42:22.000000000 -0400
+++ libpbe/include/endian.hh	2014-08-15 14:42:47.000000000 -0400
@@ -29,6 +29,7 @@
 
 #elif defined(__FreeBSD__)
 #include <machine/endian.h>
+#include <sys/types.h>
 #define PBE_BYTE_ORDER _BYTE_ORDER
 #define PBE_BIG_ENDIAN _BIG_ENDIAN
 #define PBE_LITTLE_ENDIAN _LITTLE_ENDIAN
