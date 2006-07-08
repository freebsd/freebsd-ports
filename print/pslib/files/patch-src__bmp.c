--- src/bmp.c.orig	Mon Apr 24 10:25:31 2006
+++ src/bmp.c	Sat Jul  8 13:02:51 2006
@@ -41,10 +41,28 @@
 #include <fcntl.h>
 #include <unistd.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+
+#if __FreeBSD_version >= 500000
+#define BMPSwabShort(x) *x = bswap16(*x)
+#define BMPSwabLong(x) *x = bswap32(*x)
+#else
+#define BMPSwabShort(x) (be16toh(x))
+#define BMPSwabLong(x) (be32toh(x))
+#endif
+#endif
+
+#ifdef linux
 #include <byteswap.h>
 
 #define BMPSwabShort(x) *x = bswap_16 (*x)
 #define BMPSwabLong(x) *x = bswap_32 (*x)
+#endif
 
 #include <inttypes.h>
 
