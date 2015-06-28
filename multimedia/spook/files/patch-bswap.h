--- bswap.h.orig	2005-02-08 02:20:14 UTC
+++ bswap.h
@@ -6,7 +6,11 @@
 #ifndef __BSWAP_H__
 #define __BSWAP_H__
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define WORDS_BIGENDIAN
 #endif
