--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -58,7 +58,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_paint_utils_linux.h"
@@ -90,7 +90,7 @@ constexpr int kContentSettingIconSize = 16;
 // The height of the controls bar at the top of the window.
 constexpr int kTopControlsHeight = 34;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Frame border when window shadow is not drawn.
 constexpr int kFrameBorderThickness = 4;
 #endif
@@ -182,7 +182,7 @@ class WindowEventObserver : public ui::EventObserver {
 
     gfx::Rect input_bounds = pip_browser_frame_view_->GetLocalBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Calculate input bounds for Linux. This is needed because the input bounds
     // is not necessary the same as the local bounds on Linux.
     if (pip_browser_frame_view_->ShouldDrawFrameShadow()) {
@@ -578,7 +578,7 @@ PictureInPictureBrowserFrameView::PictureInPictureBrow
         AddChildView(std::move(auto_pip_setting_overlay));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -800,7 +800,7 @@ void PictureInPictureBrowserFrameView::OnThemeChanged(
   for (ContentSettingImageView* view : content_setting_views_)
     view->SetIconColor(color_provider->GetColor(kColorPipWindowForeground));
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // On Linux the top bar background will be drawn in OnPaint().
   top_bar_container_view_->SetBackground(views::CreateSolidBackground(
       color_provider->GetColor(kColorPipWindowTopBarBackground)));
@@ -882,7 +882,7 @@ void PictureInPictureBrowserFrameView::RemovedFromWidg
   BrowserNonClientFrameView::RemovedFromWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets PictureInPictureBrowserFrameView::MirroredFrameBorderInsets()
     const {
   auto border = FrameBorderInsets();
@@ -1138,7 +1138,7 @@ void PictureInPictureBrowserFrameView::AnimationProgre
 // views::View implementations:
 
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Draw the PiP window frame borders and shadows, including the top bar
   // background.
   if (window_frame_provider_) {
@@ -1272,7 +1272,7 @@ void PictureInPictureBrowserFrameView::UpdateTopBarVie
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const bool tiled = frame()->tiled();
@@ -1290,7 +1290,7 @@ gfx::Insets PictureInPictureBrowserFrameView::FrameBor
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::ResizeBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderInsets();
 #elif !BUILDFLAG(IS_CHROMEOS_ASH)
   return gfx::Insets(kResizeBorder);
@@ -1311,7 +1311,7 @@ gfx::Size PictureInPictureBrowserFrameView::GetNonClie
                    top_height + border_thickness.bottom());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool PictureInPictureBrowserFrameView::ShouldDrawFrameShadow() const {
   return static_cast<DesktopBrowserFrameAuraLinux*>(
              frame()->native_browser_frame())
