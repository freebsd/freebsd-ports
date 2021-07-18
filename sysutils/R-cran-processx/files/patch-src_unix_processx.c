--- src/unix/processx.c.orig	2021-04-21 01:17:03 UTC
+++ src/unix/processx.c
@@ -30,6 +30,8 @@ void processx__create_connections(processx_handle_t *h
 #ifdef WORDS_BIGENDIAN
 #if (defined(__sun) && defined(__SVR4))
 #include <sys/byteorder.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #elif (defined(__APPLE__) && defined(__ppc__) || defined(__ppc64__))
 #include <libkern/OSByteOrder.h>
 #define BSWAP_32 OSSwapInt32
