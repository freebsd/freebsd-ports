--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -69,7 +69,7 @@
 
 // Windows, Mac and CrOS do not clip child widgets to their parents, so we
 // don't have to worry about resizing quite as much.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_CLIPS_CHILD_WINDOWS
 #endif
 
