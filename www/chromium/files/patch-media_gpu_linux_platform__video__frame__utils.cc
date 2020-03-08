--- media/gpu/linux/platform_video_frame_utils.cc.orig	2020-03-03 18:53:55 UTC
+++ media/gpu/linux/platform_video_frame_utils.cc
@@ -20,16 +20,16 @@
 #include "ui/gfx/linux/native_pixmap_dmabuf.h"
 #include "ui/gfx/native_pixmap.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_client_ids.h"
 #include "gpu/ipc/service/gpu_memory_buffer_factory.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace media {
 
 namespace {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 scoped_refptr<VideoFrame> CreateVideoFrameGpu(
     gpu::GpuMemoryBufferFactory* factory,
@@ -93,7 +93,7 @@ scoped_refptr<VideoFrame> CreateVideoFrameGpu(
                      gpu::kPlatformVideoFramePoolClientId));
   return frame;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace
 
@@ -105,11 +105,11 @@ scoped_refptr<VideoFrame> CreatePlatformVideoFrame(
     const gfx::Size& natural_size,
     base::TimeDelta timestamp,
     gfx::BufferUsage buffer_usage) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return CreateVideoFrameGpu(gpu_memory_buffer_factory, pixel_format,
                              coded_size, visible_rect, natural_size, timestamp,
                              buffer_usage);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   NOTREACHED();
   return nullptr;
 }
