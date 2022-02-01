--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc
@@ -147,7 +147,7 @@ bool BrowserDesktopWindowTreeHostLinux::SupportsClient
 }
 
 void BrowserDesktopWindowTreeHostLinux::UpdateFrameHints() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   auto* view = static_cast<BrowserFrameViewLinux*>(
       native_frame_->browser_frame()->GetFrameView());
   auto* layout = view->layout();
