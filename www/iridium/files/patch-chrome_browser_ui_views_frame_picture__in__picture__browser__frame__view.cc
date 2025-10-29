--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -75,7 +75,7 @@
 
 // Windows, Mac and CrOS do not clip child widgets to their parents, so we
 // don't have to worry about resizing quite as much.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_CLIPS_CHILD_WINDOWS
 #endif
 
