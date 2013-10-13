--- v8/src/platform-posix.h.orig	2013-10-05 16:38:26.000000000 +0200
+++ v8/src/platform-posix.h	2013-10-13 19:06:41.000000000 +0200
@@ -28,6 +28,7 @@
 #ifndef V8_PLATFORM_POSIX_H_
 #define V8_PLATFORM_POSIX_H_
 
+#include <unistd.h> // size_t
 #if !defined(ANDROID)
 #include <cxxabi.h>
 #endif
