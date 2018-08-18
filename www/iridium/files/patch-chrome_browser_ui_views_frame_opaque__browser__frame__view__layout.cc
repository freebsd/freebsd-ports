--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc.orig	2018-05-09 21:05:40.000000000 +0200
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc	2018-08-16 09:13:39.899230000 +0200
@@ -20,7 +20,7 @@
 
 const int kCaptionButtonHeight = 18;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Default extra space between the top of the frame and the top of the window
 // caption buttons.
 const int kExtraCaption = 2;
