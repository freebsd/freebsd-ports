--- extract_compressed_fs.c.orig	Sun Oct 26 04:57:09 2003
+++ extract_compressed_fs.c	Mon Jan 19 05:28:47 2004
@@ -8,7 +8,30 @@
 #include <errno.h>
 #include <string.h>
 #include <zlib.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#include <netinet/in.h>
+typedef uint64_t loff_t;
+#ifndef be64toh
+static __inline __uint64_t
+__bswap64(__uint64_t _x)
+{
+
+	return ((_x >> 56) | ((_x >> 40) & 0xff00) | ((_x >> 24) & 0xff0000) |
+	    ((_x >> 8) & 0xff000000) | ((_x << 8) & ((__uint64_t)0xff << 32)) |
+	    ((_x << 24) & ((__uint64_t)0xff << 40)) |
+	    ((_x << 40) & ((__uint64_t)0xff << 48)) | ((_x << 56)));
+}
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define be64toh(x)	__bswap64(x)
+#else
+#define be64toh(x)
+#endif
+#endif
+#define __be64_to_cpu be64toh
+#else
 #include <asm/byteorder.h>
+#endif
 #include "compressed_loop.h"
 
 struct compressed_block
