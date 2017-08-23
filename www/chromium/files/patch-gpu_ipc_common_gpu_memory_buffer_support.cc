--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2017-08-02 17:06:53.520243000 +0200
+++ gpu/ipc/common/gpu_memory_buffer_support.cc	2017-08-02 17:07:52.198146000 +0200
@@ -7,7 +7,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/client_native_pixmap_factory.h"
 #endif
 
@@ -17,7 +17,7 @@
 #if defined(OS_MACOSX)
   return gfx::IO_SURFACE_BUFFER;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return gfx::NATIVE_PIXMAP;
 #endif
   return gfx::EMPTY_BUFFER;
@@ -47,7 +47,7 @@
   return false;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!gfx::ClientNativePixmapFactory::GetInstance()) {
     // unittests don't have to set ClientNativePixmapFactory.
     return false;
