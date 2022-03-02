--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc
@@ -146,7 +146,7 @@ bool BrowserDesktopWindowTreeHostLinux::SupportsClient
 }
 
 void BrowserDesktopWindowTreeHostLinux::UpdateFrameHints() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* view = static_cast<BrowserFrameViewLinux*>(
       native_frame_->browser_frame()->GetFrameView());
   auto* layout = view->layout();
