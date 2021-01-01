--- media/gpu/buffer_validation.cc.orig	2019-12-17 19:41:51 UTC
+++ media/gpu/buffer_validation.cc
@@ -12,15 +12,15 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (fd < 0) {
     VLOGF(1) << "Invalid file descriptor";
     return false;
@@ -46,7 +46,7 @@ bool GetFileSize(const int fd, size_t* size) {
 #else
   NOTIMPLEMENTED();
   return false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 bool VerifyGpuMemoryBufferHandle(media::VideoPixelFormat pixel_format,
@@ -56,7 +56,7 @@ bool VerifyGpuMemoryBufferHandle(media::VideoPixelForm
     VLOGF(1) << "Unexpected GpuMemoryBufferType: " << gmb_handle.type;
     return false;
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
@@ -108,7 +108,7 @@ bool VerifyGpuMemoryBufferHandle(media::VideoPixelForm
 #else
   NOTIMPLEMENTED();
   return false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 }  // namespace media
