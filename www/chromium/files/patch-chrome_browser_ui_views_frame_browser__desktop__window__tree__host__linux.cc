--- chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/views/frame/browser_desktop_window_tree_host_linux.cc
@@ -151,7 +151,7 @@ bool BrowserDesktopWindowTreeHostLinux::SupportsClient
 }
 
 void BrowserDesktopWindowTreeHostLinux::UpdateFrameHints() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* view = static_cast<BrowserFrameViewLinux*>(
       native_frame_->browser_frame()->GetFrameView());
   auto* layout = view->layout();
