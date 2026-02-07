--- console/showqt.c.orig	2020-05-15 23:32:25 UTC
+++ console/showqt.c
@@ -16,6 +16,15 @@
 # define PRIx64 "llx"
 #endif
 
+#if !defined(PRId64)
+#define PRId64    "lld"
+#endif
+
+#if !defined(PRIx64)
+#define PRIx64    "llX"
+#endif
+
+
 #if BYTE_ORDER == LITTLE_ENDIAN
 # define SWAP2(x) ((((uint16_t)x>>8)  & (uint16_t)0x00ff) |\
 		   (((uint16_t)x<<8)  & (uint16_t)0xff00))
