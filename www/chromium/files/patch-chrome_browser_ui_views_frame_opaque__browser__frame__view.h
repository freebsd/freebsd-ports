--- chrome/browser/ui/views/frame/opaque_browser_frame_view.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.h
@@ -104,7 +104,7 @@ class OpaqueBrowserFrameView : public BrowserFrameView
   FrameButtonStyle GetFrameButtonStyle() const override;
   void UpdateWindowControlsOverlay(const gfx::Rect& bounding_rect) override;
   bool ShouldDrawRestoredFrameShadow() const override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsTiled() const override;
 #endif
   int WebAppButtonHeight() const override;
@@ -227,7 +227,7 @@ class OpaqueBrowserFrameView : public BrowserFrameView
   // Background painter for the window frame.
   std::unique_ptr<views::FrameBackground> frame_background_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<views::MenuRunner> menu_runner_;
 #endif
 
