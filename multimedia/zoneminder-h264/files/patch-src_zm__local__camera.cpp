--- src/zm_local_camera.cpp.orig	2016-10-03 17:21:50 UTC
+++ src/zm_local_camera.cpp
@@ -33,7 +33,7 @@
 #include <limits.h>
 
 /* Workaround for GNU/kFreeBSD */
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
 #ifndef ENODATA
 #define ENODATA ENOATTR
 #endif
