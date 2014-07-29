--- console/showqt.c.orig	Tue Nov 19 23:49:53 2002
+++ console/showqt.c	Tue Nov 19 23:57:26 2002
@@ -11,6 +11,15 @@
 #include <inttypes.h>
 #include <time.h>
 
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
 # define SWAP2(x) (((x>>8) & 0x00ff) |\
                    ((x<<8) & 0xff00))
