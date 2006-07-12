--- bswap.h.orig	Sun Jun 11 20:35:47 2006
+++ bswap.h	Thu Jun 15 10:31:42 2006
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
