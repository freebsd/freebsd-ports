--- dvdread/bswap.h.orig	Wed Mar  5 23:13:17 2003
+++ dvdread/bswap.h	Wed Mar  5 23:14:24 2003
@@ -57,7 +57,15 @@
 #include <sys/endian.h>
 #define B2N_16(x) x = be16toh(x)
 #define B2N_32(x) x = be32toh(x)
-#define B2N_64(x) x = be64toh(x)
+#define B2N_64(x) x = \
+ x = ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
 
 /* This is a slow but portable implementation, it has multiple evaluation 
  * problems so beware.
