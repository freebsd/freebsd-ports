--- ui/gl/gl_fence.cc.orig	2018-08-04 21:33:30.691170000 +0200
+++ ui/gl/gl_fence.cc	2018-08-04 21:33:47.409485000 +0200
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(USE_EGL) && defined(OS_POSIX) && !defined(OS_FUCHSIA) && \
-    !defined(OS_MACOSX)
+    !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #include "ui/gl/gl_surface_egl.h"
