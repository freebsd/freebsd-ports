--- dvdread/bswap.h.orig	Sat Nov 23 18:53:53 2002
+++ dvdread/bswap.h	Sat Nov 23 18:57:27 2002
@@ -54,6 +54,14 @@
  * functionality! 
  */
 
+#elif defined(__FreeBSD__)
+#  define _KERNEL
+#  define I486_CPU     /* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#  define FROM_BE_32(x) (ntohl(x))
+
 #elif defined(__FreeBSD__) || defined(__sun) || defined(__bsdi__)
 #define B2N_16(x) \
  x = ((((x) & 0xff00) >> 8) | \
