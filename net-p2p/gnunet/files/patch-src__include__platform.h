--- src/include/platform.h.orig	2009-10-01 07:11:14.000000000 +0900
+++ src/include/platform.h	2010-01-05 00:27:09.000000000 +0900
@@ -189,6 +189,7 @@
 #endif
 
 #ifdef FREEBSD
+typedef int error_t;
 #define __BYTE_ORDER BYTE_ORDER
 #define __BIG_ENDIAN BIG_ENDIAN
 #endif
