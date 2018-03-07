--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2018-02-24 16:25:15.000000000 +0100
+++ gpu/ipc/common/gpu_memory_buffer_support.cc	2018-03-04 02:34:29.021605000 +0100
@@ -7,7 +7,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/client_native_pixmap_factory.h"
 #endif
 
@@ -22,7 +22,7 @@
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -81,7 +81,7 @@
   }
   NOTREACHED();
   return false;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!gfx::ClientNativePixmapFactory::GetInstance()) {
     // unittests don't have to set ClientNativePixmapFactory.
     return false;
