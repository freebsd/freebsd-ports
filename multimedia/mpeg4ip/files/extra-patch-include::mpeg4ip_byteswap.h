--- include/mpeg4ip_byteswap.h.orig	Wed Nov 13 16:40:27 2002
+++ include/mpeg4ip_byteswap.h	Wed Nov 13 16:42:01 2002
@@ -50,6 +50,26 @@
 #define B2N_32(x) x = swap32(x)
 #define B2N_64(x) x = swap64(x)
 
+#elif defined(__FreeBSD__)
+#  define _KERNEL
+#  define I486_CPU	/* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#define B2N_16(x) \
+ x = ((((x) & 0xff00) >> 8) | \
+      (((x) & 0x00ff) << 8))
+#define B2N_32(x) (ntohl(x))
+#define B2N_64(x) \
+ x = ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
+
 /* This is a slow but portable implementation, it has multiple evaluation 
  * problems so beware.
  * FreeBSD and Solaris don't have <byteswap.h> or any other such 
