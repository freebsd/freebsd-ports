--- gpu/ipc/common/gpu_memory_buffer_support.h.orig	2018-07-19 13:55:08.335420000 +0200
+++ gpu/ipc/common/gpu_memory_buffer_support.h	2018-07-19 13:56:28.243213000 +0200
@@ -17,7 +17,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
@@ -29,7 +29,7 @@
 class GPU_EXPORT GpuMemoryBufferSupport {
  public:
   GpuMemoryBufferSupport();
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
   GpuMemoryBufferSupport(std::unique_ptr<gfx::ClientNativePixmapFactory>
                              client_native_pixmap_factory);
 #endif
@@ -43,7 +43,7 @@
   bool IsNativeGpuMemoryBufferConfigurationSupported(gfx::BufferFormat format,
                                                      gfx::BufferUsage usage);
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
   gfx::ClientNativePixmapFactory* client_native_pixmap_factory() {
     return client_native_pixmap_factory_.get();
   }
@@ -66,7 +66,7 @@
       const GpuMemoryBufferImpl::DestructionCallback& callback);
 
  private:
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(USE_OZONE)
   std::unique_ptr<gfx::ClientNativePixmapFactory> client_native_pixmap_factory_;
 #endif
 
