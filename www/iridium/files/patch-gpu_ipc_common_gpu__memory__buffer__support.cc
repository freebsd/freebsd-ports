--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2019-03-11 22:00:59 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -12,7 +12,7 @@
 #include "gpu/ipc/common/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/client_native_pixmap_factory.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
@@ -37,7 +37,7 @@ namespace gpu {
 GpuMemoryBufferSupport::GpuMemoryBufferSupport() {
 #if defined(USE_OZONE)
   client_native_pixmap_factory_ = ui::CreateClientNativePixmapFactoryOzone();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   client_native_pixmap_factory_.reset(
       gfx::CreateClientNativePixmapFactoryDmabuf());
 #endif
@@ -51,7 +51,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -109,7 +109,7 @@ bool GpuMemoryBufferSupport::IsNativeGpuMemoryBufferCo
 #elif defined(USE_OZONE)
   return ui::OzonePlatform::EnsureInstance()->IsNativePixmapConfigSupported(
       format, usage);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return false;  // TODO(julian.isorce): Add linux support.
 #elif defined(OS_WIN)
   switch (usage) {
@@ -166,7 +166,7 @@ GpuMemoryBufferSupport::CreateGpuMemoryBufferImplFromH
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           std::move(handle), size, format, usage, std::move(callback));
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           client_native_pixmap_factory(), std::move(handle), size, format,
