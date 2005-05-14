--- libavcodec/bswap.h.orig	Tue May 10 15:54:38 2005
+++ libavcodec/bswap.h	Fri May 13 02:12:48 2005
@@ -6,8 +6,31 @@
 #ifndef __BSWAP_H__
 #define __BSWAP_H__
 
+/* to detect __FreeBSD_version */
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
+#elif (defined(__FreeBSD__) && __FreeBSD_version <= 500000)
+#include <sys/endian.h>
+#define bswap_16(x) be16toh(x)
+#define bswap_32(x) be32toh(x)
+#define bswap_64(x) \
+  x = ((((x) & 0xff00000000000000) >> 56) | \
+       (((x) & 0x00ff000000000000) >> 40) | \
+       (((x) & 0x0000ff0000000000) >> 24) | \
+       (((x) & 0x000000ff00000000) >>  8) | \
+       (((x) & 0x00000000ff000000) <<  8) | \
+       (((x) & 0x0000000000ff0000) << 24) | \
+       (((x) & 0x000000000000ff00) << 40) | \
+       (((x) & 0x00000000000000ff) << 56))
 #else
 
 #ifdef ARCH_X86_64
