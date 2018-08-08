--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc.orig	2018-08-01 00:08:32.000000000 +0200
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout.cc	2018-08-04 17:27:55.912686000 +0200
@@ -21,7 +21,7 @@
 
 constexpr int kCaptionButtonHeight = 18;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Default spacing around window caption buttons.
 constexpr int kCaptionButtonSpacing = 2;
 #else
