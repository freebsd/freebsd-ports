--- gpu/ipc/service/gpu_memory_buffer_factory.cc.orig	2017-08-02 17:22:32.367729000 +0200
+++ gpu/ipc/service/gpu_memory_buffer_factory.cc	2017-08-02 17:22:51.485749000 +0200
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/service/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -24,7 +24,7 @@
 #if defined(OS_MACOSX)
   return base::WrapUnique(new GpuMemoryBufferFactoryIOSurface);
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return base::WrapUnique(new GpuMemoryBufferFactoryNativePixmap);
 #endif
   return nullptr;
