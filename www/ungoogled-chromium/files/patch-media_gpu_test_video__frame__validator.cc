--- media/gpu/test/video_frame_validator.cc.orig	2025-09-10 13:22:16 UTC
+++ media/gpu/test/video_frame_validator.cc
@@ -29,7 +29,7 @@
 #include "media/media_buildflags.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
