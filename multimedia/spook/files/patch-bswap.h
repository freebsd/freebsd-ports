--- bswap.h.orig	2008-09-02 14:40:15.000000000 +0100
+++ bswap.h	2008-09-02 14:41:51.000000000 +0100
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
