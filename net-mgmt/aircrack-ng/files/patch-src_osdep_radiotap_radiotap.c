--- src/osdep/radiotap/radiotap.c.orig	2014-03-31 01:39:15 UTC
+++ src/osdep/radiotap/radiotap.c
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
