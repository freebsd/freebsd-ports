--- libavutil/bswap.h.orig	2007-10-08 03:49:34.000000000 +0800
+++ libavutil/bswap.h	2007-10-20 15:54:54.000000000 +0800
@@ -29,8 +29,17 @@
 #include <stdint.h>
 #include "common.h"
 
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
