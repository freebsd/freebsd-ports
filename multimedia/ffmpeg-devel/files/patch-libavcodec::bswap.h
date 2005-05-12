--- libavcodec/bswap.h.orig	Sun May  8 20:40:17 2005
+++ libavcodec/bswap.h	Sun May  8 20:45:51 2005
@@ -6,8 +6,18 @@
 #ifndef __BSWAP_H__
 #define __BSWAP_H__
 
+/* to detect __FreeBSD_version */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif (defined(__FreeBSD__) && __FreeBSD_version >= 470000)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 
 #ifdef ARCH_X86_64
