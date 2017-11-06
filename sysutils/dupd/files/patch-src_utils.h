--- src/utils.h.orig	2017-02-26 10:05:09 UTC
+++ src/utils.h
@@ -37,6 +37,11 @@
 #define LSTAT lstat
 #endif
 
+#ifdef __FreeBSD__
+#define STRUCT_STAT struct stat
+#define LSTAT lstat
+#endif
+
 #ifdef sun
 #define STRUCT_STAT struct stat64
 #define LSTAT lstat64
