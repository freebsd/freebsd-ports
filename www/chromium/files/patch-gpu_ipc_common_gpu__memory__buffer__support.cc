--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2020-07-07 21:58:16 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -15,7 +15,7 @@
 #include "gpu/ipc/common/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/client_native_pixmap_factory.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -25,7 +25,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if defined(USE_OZONE) || defined(OS_LINUX)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -43,7 +43,7 @@ namespace gpu {
 GpuMemoryBufferSupport::GpuMemoryBufferSupport() {
 #if defined(USE_OZONE)
   client_native_pixmap_factory_ = ui::CreateClientNativePixmapFactoryOzone();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   client_native_pixmap_factory_.reset(
       gfx::CreateClientNativePixmapFactoryDmabuf());
 #endif
@@ -57,7 +57,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif defined(OS_LINUX) || defined(USE_OZONE)
+#elif defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -182,7 +182,7 @@ GpuMemoryBufferSupport::CreateGpuMemoryBufferImplFromH
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           std::move(handle), size, format, usage, std::move(callback));
 #endif
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           client_native_pixmap_factory(), std::move(handle), size, format,
