--- src/util/tss2_endian.h.orig	2019-08-21 19:14:09 UTC
+++ src/util/tss2_endian.h
@@ -9,7 +9,11 @@
 #define TSS2_ENDIAN_H
 
 #if defined(__linux__) || defined(__unix__)
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #define HOST_TO_BE_16(value) htobe16(value)
 #define HOST_TO_BE_32(value) htobe32(value)
