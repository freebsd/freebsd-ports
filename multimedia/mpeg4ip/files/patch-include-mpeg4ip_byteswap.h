--- include/mpeg4ip_byteswap.h.orig	Mon Jul 22 14:27:09 2002
+++ include/mpeg4ip_byteswap.h	Sun Nov  7 03:57:01 2004
@@ -24,6 +24,10 @@
 #include <config.h>
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(WORDS_BIGENDIAN)
 /* All bigendian systems are fine, just ignore the swaps. */  
 #define B2N_16(x) (x)
@@ -55,6 +59,24 @@
  * FreeBSD and Solaris don't have <byteswap.h> or any other such 
  * functionality! 
  */
+
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#define B2N_16(x) (be16toh(x))
+#define B2N_32(x) (be32toh(x))
+# if __FreeBSD_version >= 510000
+#define B2N_64(x) (be64toh(x))
+# else
+#define B2N_64(x) \
+ x = ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
+# endif
 
 #elif defined(__FreeBSD__) || defined(__sun) || defined(__bsdi__) || defined(_WIN32)
 #define B2N_16(x) \
