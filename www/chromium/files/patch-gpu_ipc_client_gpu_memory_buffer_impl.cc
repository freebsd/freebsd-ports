--- gpu/ipc/client/gpu_memory_buffer_impl.cc.orig	2017-08-02 17:20:25.306294000 +0200
+++ gpu/ipc/client/gpu_memory_buffer_impl.cc	2017-08-02 17:20:50.656124000 +0200
@@ -12,7 +12,7 @@
 #include "gpu/ipc/client/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/client/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -50,7 +50,7 @@
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           handle, size, format, usage, callback);
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           handle, size, format, usage, callback);
