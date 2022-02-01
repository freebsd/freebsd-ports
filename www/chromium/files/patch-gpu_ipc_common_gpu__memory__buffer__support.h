--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2021-12-14 11:45:06 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(USE_OZONE)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
@@ -46,7 +46,7 @@ class GPU_EXPORT GpuMemoryBufferSupport {
   bool IsNativeGpuMemoryBufferConfigurationSupported(gfx::BufferFormat format,
                                                      gfx::BufferUsage usage);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(USE_OZONE)
   gfx::ClientNativePixmapFactory* client_native_pixmap_factory() {
     return client_native_pixmap_factory_.get();
   }
@@ -74,7 +74,7 @@ class GPU_EXPORT GpuMemoryBufferSupport {
       scoped_refptr<base::UnsafeSharedMemoryPool> pool = nullptr);
 
  private:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(USE_OZONE)
   std::unique_ptr<gfx::ClientNativePixmapFactory> client_native_pixmap_factory_;
 #endif
 };
