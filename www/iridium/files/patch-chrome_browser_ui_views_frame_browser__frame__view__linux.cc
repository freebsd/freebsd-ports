--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -71,7 +71,7 @@ gfx::ShadowValues BrowserFrameViewLinux::GetShadowValu
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
@@ -126,7 +126,7 @@ int BrowserFrameViewLinux::NonClientHitTest(const gfx:
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
