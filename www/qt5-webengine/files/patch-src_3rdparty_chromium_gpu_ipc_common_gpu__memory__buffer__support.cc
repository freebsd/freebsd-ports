--- src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -12,7 +12,7 @@
 #include "gpu/ipc/common/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/client_native_pixmap_factory.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
@@ -36,13 +36,13 @@ namespace gpu {
 GpuMemoryBufferSupport::GpuMemoryBufferSupport() {
 #if defined(USE_OZONE)
   client_native_pixmap_factory_ = ui::CreateClientNativePixmapFactoryOzone();
-#elif defined(OS_LINUX) && !defined(TOOLKIT_QT)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
   client_native_pixmap_factory_.reset(
       gfx::CreateClientNativePixmapFactoryDmabuf());
 #endif
 }
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
 GpuMemoryBufferSupport::GpuMemoryBufferSupport(
     std::unique_ptr<gfx::ClientNativePixmapFactory>
         client_native_pixmap_factory)
@@ -57,7 +57,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif defined(OS_LINUX) && !defined(TOOLKIT_QT)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -114,7 +114,7 @@ bool GpuMemoryBufferSupport::IsNativeGpuMemoryBufferCo
   return false;
 #elif defined(USE_OZONE)
   return client_native_pixmap_factory_->IsConfigurationSupported(format, usage);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return false;  // TODO(julian.isorce): Add linux support.
 #elif defined(OS_WIN)
   switch (usage) {
@@ -171,7 +171,7 @@ GpuMemoryBufferSupport::CreateGpuMemoryBufferImplFromH
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           std::move(handle), size, format, usage, callback);
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           client_native_pixmap_factory(), std::move(handle), size, format,
