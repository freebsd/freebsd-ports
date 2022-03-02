--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2022-02-28 16:54:41 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -21,7 +21,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
