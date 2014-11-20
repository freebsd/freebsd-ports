--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc
@@ -82,7 +82,7 @@
 // is no avatar icon.
 const int kTabStripIndent = -6;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 // Default extra space between the top of the frame and the top of the window
 // caption buttons.
 const int kExtraCaption = 2;
