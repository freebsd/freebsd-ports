--- ../ark/plugins/libzipplugin/zipplugin.cpp.orig	2008-12-10 16:13:03.000000000 +0000
+++ ../ark/plugins/libzipplugin/zipplugin.cpp	2008-12-29 22:16:13.000000000 +0000
@@ -28,8 +28,8 @@
 
 #ifdef LIBZIP_COMPILED_WITH_32BIT_OFF_T
 
-#define __off_t_defined
-typedef quint32 off_t;
+// #define __off_t_defined
+// typedef quint32 off_t;
 
 #endif /* LIBZIP_COMPILED_WITH_32BIT_OFF_T */
 
