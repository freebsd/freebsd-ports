--- bswap.h.orig	Thu Oct 21 08:54:57 2004
+++ bswap.h	Mon May  9 20:57:34 2005
@@ -1,8 +1,17 @@
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
 
 #include <inttypes.h>
