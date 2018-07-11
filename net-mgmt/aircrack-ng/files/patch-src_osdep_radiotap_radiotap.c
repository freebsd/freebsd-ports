--- src/aircrack-osdep/radiotap/radiotap.c.orig
+++ src/aircrack-osdep/radiotap/radiotap.c
@@ -20,6 +20,16 @@
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
