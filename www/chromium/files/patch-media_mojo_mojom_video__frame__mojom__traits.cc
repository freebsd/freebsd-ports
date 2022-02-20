--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2022-02-07 13:39:41 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -21,7 +21,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
