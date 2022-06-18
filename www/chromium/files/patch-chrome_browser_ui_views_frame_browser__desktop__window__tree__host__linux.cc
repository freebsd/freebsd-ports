--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc
@@ -145,7 +145,7 @@ bool BrowserDesktopWindowTreeHostLinux::SupportsClient
 }
 
 void BrowserDesktopWindowTreeHostLinux::UpdateFrameHints() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* view = static_cast<BrowserFrameViewLinux*>(
       native_frame_->browser_frame()->GetFrameView());
   auto* layout = view->layout();
