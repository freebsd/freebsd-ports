--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -60,7 +60,7 @@ gfx::ShadowValues BrowserFrameViewLinux::GetShadowValu
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -104,7 +104,7 @@ void BrowserFrameViewLinux::OnWindowButtonOrderingChan
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
