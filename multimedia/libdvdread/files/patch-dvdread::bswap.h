--- dvdread/bswap.h.orig	Sat Nov 23 18:53:53 2002
+++ dvdread/bswap.h	Sat Nov 23 18:56:21 2002
@@ -22,6 +22,10 @@
 
 #include <config.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(WORDS_BIGENDIAN)
 /* All bigendian systems are fine, just ignore the swaps. */  
 #define B2N_16(x) (void)(x)
@@ -53,6 +57,20 @@
  * FreeBSD and Solaris don't have <byteswap.h> or any other such 
  * functionality! 
  */
+
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#define B2N_16(x) x = (be16toh(x))
+#define B2N_32(x) x = (be32toh(x))
+#define B2N_64(x) \
+ x = ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
 
 #elif defined(__FreeBSD__) || defined(__sun) || defined(__bsdi__)
 #define B2N_16(x) \
