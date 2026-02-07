--- media/gpu/test/video_frame_helpers.cc.orig	2025-12-10 15:04:57 UTC
+++ media/gpu/test/video_frame_helpers.cc
@@ -22,7 +22,7 @@
 #include "third_party/libyuv/include/libyuv.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
