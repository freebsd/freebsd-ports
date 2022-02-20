--- media/gpu/buffer_validation.cc.orig	2022-02-07 13:39:41 UTC
+++ media/gpu/buffer_validation.cc
@@ -12,7 +12,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -20,7 +20,7 @@
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (fd < 0) {
     VLOGF(1) << "Invalid file descriptor";
     return false;
@@ -56,7 +56,7 @@ bool VerifyGpuMemoryBufferHandle(media::VideoPixelForm
     VLOGF(1) << "Unexpected GpuMemoryBufferType: " << gmb_handle.type;
     return false;
   }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
