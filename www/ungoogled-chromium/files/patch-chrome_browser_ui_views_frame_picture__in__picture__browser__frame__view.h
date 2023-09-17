--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2023-09-17 07:59:53 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -23,7 +23,7 @@
 #include "ui/views/controls/image_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -86,7 +86,7 @@ class PictureInPictureBrowserFrameView
   void Layout() override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets MirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -175,7 +175,7 @@ class PictureInPictureBrowserFrameView
   // Called when mouse entered or exited the pip window.
   void OnMouseEnteredOrExitedWindow(bool entered);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets the window frame provider so that it will be used for drawing.
   void SetWindowFrameProvider(ui::WindowFrameProvider* window_frame_provider);
 
@@ -258,7 +258,7 @@ class PictureInPictureBrowserFrameView
   // `top_bar_color_animation_`.
   absl::optional<SkColor> current_foreground_color_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
