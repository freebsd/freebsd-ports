--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h
@@ -20,7 +20,7 @@
 #include "ui/views/layout/box_layout_view.h"
 #include "ui/views/widget/widget_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/window_frame_provider.h"
 #endif
 
@@ -67,7 +67,7 @@ class PictureInPictureBrowserFrameView
   void OnThemeChanged() override;
   void Layout() override;
   void AddedToWidget() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::Insets MirroredFrameBorderInsets() const override;
   gfx::Insets GetInputInsets() const override;
   SkRRect GetRestoredClipRegion() const override;
@@ -145,7 +145,7 @@ class PictureInPictureBrowserFrameView
   // Returns the height of the top bar area, including the window top border.
   int GetTopAreaHeight() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Sets the window frame provider so that it will be used for drawing.
   void SetWindowFrameProvider(ui::WindowFrameProvider* window_frame_provider);
 
@@ -177,7 +177,7 @@ class PictureInPictureBrowserFrameView
       widget_observation_{this};
   bool mouse_inside_window_ = false;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to draw window frame borders and shadow on Linux when GTK theme is
   // enabled.
   raw_ptr<ui::WindowFrameProvider> window_frame_provider_ = nullptr;
