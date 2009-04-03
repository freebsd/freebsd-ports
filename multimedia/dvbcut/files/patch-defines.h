--- src/defines.h.orig	2007-09-30 23:31:46.000000000 +0900
+++ src/defines.h	2009-03-27 01:33:10.000000000 +0900
@@ -42,6 +42,12 @@
 #endif
   }
 
+#if defined(__FreeBSD__)
+#define mbo32(x) htobe32(x)
+#define htom32(x) htobe32(x)
+#define mbo16(x) htobe16(x)
+#define htom16(x) htobe16(x)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define mbo32(x) \
       ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
@@ -55,5 +61,6 @@
 #define mbo16(x) (x)
 #define htom16(x) (x)
 #endif
+#endif
 
 #endif
