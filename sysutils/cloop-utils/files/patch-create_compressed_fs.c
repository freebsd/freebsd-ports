--- create_compressed_fs.c.orig	Sun Oct 26 05:15:22 2003
+++ create_compressed_fs.c	Tue Jan 20 03:37:34 2004
@@ -18,7 +18,30 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#include <netinet/in.h>
+typedef uint64_t loff_t;
+#ifndef htobe64
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
+#define htobe64(x)	__bswap64(x)
+#else
+#define htobe64(x)
+#endif
+#endif
+#define __cpu_to_be64 htobe64
+#else
 #include <asm/byteorder.h>
+#endif
 #include <fcntl.h>
 #include <zlib.h>
 #include "compressed_loop.h"
@@ -195,6 +218,23 @@
    cbp=cbp->next;
    free(compressed_blocks); compressed_blocks=cbp;
   }
+#if defined(__FreeBSD__)
+ /*
+  * FreeBSD requires padding to 512 byte boundary
+  */
+ bytes_so_far = lseek(STDOUT_FILENO, 0, SEEK_END);
+ if (bytes_so_far % 512)
+  {
+   static char padding[512];
+   off_t len = 512 - bytes_so_far % 512;
+
+   if (write(STDOUT_FILENO, padding, len) != len)
+    {
+     perror("writing padding block");
+     return 1;
+    }
+  }
+#endif
  fprintf(stderr,"Done.\n");
  return 0;
 }
