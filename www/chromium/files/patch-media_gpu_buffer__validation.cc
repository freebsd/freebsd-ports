--- media/gpu/buffer_validation.cc.orig	2022-02-28 16:54:41 UTC
+++ media/gpu/buffer_validation.cc
@@ -12,7 +12,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -20,7 +20,7 @@
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (fd < 0) {
     VLOGF(1) << "Invalid file descriptor";
     return false;
@@ -56,7 +56,7 @@ bool VerifyGpuMemoryBufferHandle(media::VideoPixelForm
     VLOGF(1) << "Unexpected GpuMemoryBufferType: " << gmb_handle.type;
     return false;
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
