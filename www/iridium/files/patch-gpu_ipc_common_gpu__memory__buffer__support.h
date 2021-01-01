--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2019-12-16 21:50:48 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
@@ -38,7 +38,7 @@ class GPU_EXPORT GpuMemoryBufferSupport {
   bool IsNativeGpuMemoryBufferConfigurationSupported(gfx::BufferFormat format,
                                                      gfx::BufferUsage usage);
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
   gfx::ClientNativePixmapFactory* client_native_pixmap_factory() {
     return client_native_pixmap_factory_.get();
   }
@@ -62,7 +62,7 @@ class GPU_EXPORT GpuMemoryBufferSupport {
       GpuMemoryBufferImpl::DestructionCallback callback);
 
  private:
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
   std::unique_ptr<gfx::ClientNativePixmapFactory> client_native_pixmap_factory_;
 #endif
 
