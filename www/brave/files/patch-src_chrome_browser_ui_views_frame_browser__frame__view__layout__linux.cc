--- src/chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -52,7 +52,7 @@ gfx::Insets BrowserFrameViewLayoutLinux:
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
