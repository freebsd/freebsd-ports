--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2023-09-13 12:11:42 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -56,7 +56,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_paint_utils_linux.h"
 #include "chrome/browser/ui/views/frame/desktop_browser_frame_aura_linux.h"
 #endif
@@ -78,7 +78,7 @@ constexpr int kBackToTabImageSize = 16;
 // The height of the controls bar at the top of the window.
 constexpr int kTopControlsHeight = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Frame border when window shadow is not drawn.
 constexpr int kFrameBorderThickness = 4;
 #endif
@@ -173,7 +173,7 @@ class WindowEventObserver : public ui::EventObserver {
 
     gfx::Rect input_bounds = pip_browser_frame_view_->GetLocalBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Calculate input bounds for Linux. This is needed because the input bounds
     // is not necessary the same as the local bounds on Linux.
     if (pip_browser_frame_view_->ShouldDrawFrameShadow()) {
@@ -399,7 +399,7 @@ PictureInPictureBrowserFrameView::PictureInPictureBrow
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   frame_background_ = std::make_unique<views::FrameBackground>();
 #endif
 
@@ -578,7 +578,7 @@ void PictureInPictureBrowserFrameView::OnThemeChanged(
   for (ContentSettingImageView* view : content_setting_views_)
     view->SetIconColor(color_provider->GetColor(kColorPipWindowForeground));
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On Linux the top bar background will be drawn in OnPaint().
   top_bar_container_view_->SetBackground(views::CreateSolidBackground(
       color_provider->GetColor(kColorPipWindowTopBarBackground)));
@@ -634,7 +634,7 @@ void PictureInPictureBrowserFrameView::RemovedFromWidg
   BrowserNonClientFrameView::RemovedFromWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets PictureInPictureBrowserFrameView::MirroredFrameBorderInsets()
     const {
   auto border = FrameBorderInsets();
@@ -875,7 +875,7 @@ void PictureInPictureBrowserFrameView::AnimationProgre
 // views::View implementations:
 
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Draw the PiP window frame borders and shadows, including the top bar
   // background.
   if (window_frame_provider_) {
@@ -998,7 +998,7 @@ void PictureInPictureBrowserFrameView::UpdateTopBarVie
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const auto tiled_edges = frame()->tiled_edges();
@@ -1019,7 +1019,7 @@ gfx::Insets PictureInPictureBrowserFrameView::FrameBor
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::ResizeBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderInsets();
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return gfx::Insets(chromeos::kResizeInsideBoundsSize);
@@ -1040,7 +1040,7 @@ gfx::Size PictureInPictureBrowserFrameView::GetNonClie
                    top_height + border_thickness.bottom());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PictureInPictureBrowserFrameView::SetWindowFrameProvider(
     ui::WindowFrameProvider* window_frame_provider) {
   DCHECK(window_frame_provider);
