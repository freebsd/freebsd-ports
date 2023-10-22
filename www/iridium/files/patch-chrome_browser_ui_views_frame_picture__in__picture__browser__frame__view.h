--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -24,7 +24,7 @@
 #include "ui/views/controls/image_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -32,7 +32,7 @@
 // window, so to prevent cutting off important dialogs we resize the
 // picture-in-picture window to fit them. While ChromeOS also uses Aura, it does
 // not have this issue so we do not resize on ChromeOS.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #define RESIZE_DOCUMENT_PICTURE_IN_PICTURE_TO_DIALOG 1
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -97,7 +97,7 @@ class PictureInPictureBrowserFrameView
   void Layout() override;
   void AddedToWidget() override;
   void RemovedFromWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets MirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -188,7 +188,7 @@ class PictureInPictureBrowserFrameView
   // Called when mouse entered or exited the pip window.
   void OnMouseEnteredOrExitedWindow(bool entered);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets the window frame provider so that it will be used for drawing.
   void SetWindowFrameProvider(ui::WindowFrameProvider* window_frame_provider);
 
@@ -355,7 +355,7 @@ class PictureInPictureBrowserFrameView
   // `top_bar_color_animation_`.
   absl::optional<SkColor> current_foreground_color_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
