--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -54,7 +54,7 @@ gfx::Insets BrowserFrameViewLayoutLinux::RestoredFrame
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
