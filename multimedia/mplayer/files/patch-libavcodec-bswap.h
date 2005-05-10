--- libavcodec/bswap.h.orig	Sat Apr 16 17:40:51 2005
+++ libavcodec/bswap.h	Mon May  9 20:47:04 2005
@@ -6,8 +6,17 @@
 #ifndef __BSWAP_H__
 #define __BSWAP_H__
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif (defined(__FreeBSD__) && __FreeBSD_version >= 500000)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 
 #ifdef ARCH_X86_64
