--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc
@@ -20,7 +20,7 @@ namespace {
 
 const int kCaptionButtonHeight = 18;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 // Default extra space between the top of the frame and the top of the window
 // caption buttons.
 const int kExtraCaption = 2;
