--- src/3rdparty/chromium/ui/gl/gl_fence.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/ui/gl/gl_fence.cc
@@ -20,7 +20,7 @@
 #endif
 
 #if defined(USE_EGL)
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #endif
