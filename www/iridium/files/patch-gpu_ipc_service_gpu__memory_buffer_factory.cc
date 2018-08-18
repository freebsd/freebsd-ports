--- gpu/ipc/service/gpu_memory_buffer_factory.cc.orig	2018-02-24 16:25:15.000000000 +0100
+++ gpu/ipc/service/gpu_memory_buffer_factory.cc	2018-03-04 02:47:09.144034000 +0100
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/service/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -33,7 +33,7 @@
   return base::WrapUnique(new GpuMemoryBufferFactoryIOSurface);
 #elif defined(OS_ANDROID)
   return base::WrapUnique(new GpuMemoryBufferFactoryAndroidHardwareBuffer);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return base::WrapUnique(new GpuMemoryBufferFactoryNativePixmap);
 #elif defined(OS_WIN)
   return base::WrapUnique(new GpuMemoryBufferFactoryDXGI);
