--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -28,7 +28,7 @@
 #include "ui/views/layout/flex_layout_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -88,7 +88,7 @@ class PictureInPictureBrowserFrameView
   void Layout(PassKey) override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets RestoredMirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -180,7 +180,7 @@ class PictureInPictureBrowserFrameView
   // Returns true if there's an overlay view that's currently shown.
   bool IsOverlayViewVisible() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether a client-side shadow should be drawn for the window.
   bool ShouldDrawFrameShadow() const;
 
@@ -351,7 +351,7 @@ class PictureInPictureBrowserFrameView
   // `top_bar_color_animation_`.
   std::optional<SkColor> current_foreground_color_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
