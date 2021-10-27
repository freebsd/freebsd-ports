--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc.orig	2021-09-24 18:31:35 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc
@@ -146,7 +146,7 @@ bool BrowserDesktopWindowTreeHostLinux::SupportsClient
 }
 
 void BrowserDesktopWindowTreeHostLinux::UpdateFrameHints() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   auto* view = static_cast<BrowserFrameViewLinux*>(
       native_frame_->browser_frame()->GetFrameView());
   auto* layout = view->layout();
