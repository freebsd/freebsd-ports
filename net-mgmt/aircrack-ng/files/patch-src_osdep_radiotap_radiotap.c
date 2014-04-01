--- src/osdep/radiotap/radiotap.c.orig	2014-04-01 19:20:56.379623336 +0200
+++ src/osdep/radiotap/radiotap.c	2014-04-01 19:22:54.880614337 +0200
@@ -19,6 +19,16 @@
 	#include "../byteorder.h"
 #endif
 
+#ifdef _BSD_SOURCE
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+#define le16toh(x) (x)
+#define le32toh(x) (x)
+#else
+#define le32toh(x) bswap_32 (x)
+#endif
+#endif
+
+
 /* function prototypes and related defs are in radiotap_iter.h */
 
 static const struct radiotap_align_size rtap_namespace_sizes[] = {
