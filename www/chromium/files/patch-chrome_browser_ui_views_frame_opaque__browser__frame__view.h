--- chrome/browser/ui/views/frame/opaque_browser_frame_view.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.h
@@ -224,7 +224,7 @@ class OpaqueBrowserFrameView : public BrowserNonClient
   // Background painter for the window frame.
   std::unique_ptr<views::FrameBackground> frame_background_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<views::MenuRunner> menu_runner_;
 #endif
 
