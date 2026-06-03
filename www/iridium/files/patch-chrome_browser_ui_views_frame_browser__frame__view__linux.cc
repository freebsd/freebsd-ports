--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2026-04-15 12:07:04 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -72,7 +72,7 @@ gfx::ShadowValues BrowserFrameViewLinux::GetShadowValu
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
@@ -127,7 +127,7 @@ int BrowserFrameViewLinux::NonClientHitTest(const gfx:
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
