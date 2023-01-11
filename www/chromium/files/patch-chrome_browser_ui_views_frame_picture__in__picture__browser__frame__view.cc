--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2023-01-11 09:17:16 UTC
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -32,7 +32,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/desktop_browser_frame_aura_linux.h"
 #endif
 
@@ -256,7 +256,7 @@ void PictureInPictureBrowserFrameView::OnThemeChanged(
   for (ContentSettingImageView* view : content_setting_views_)
     view->SetIconColor(color_provider->GetColor(kColorOmniboxResultsIcon));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the top bar background is already drawn by window_frame_provider_, skip
   // drawing it again below.
   if (window_frame_provider_) {
@@ -292,7 +292,7 @@ void PictureInPictureBrowserFrameView::AddedToWidget()
   BrowserNonClientFrameView::AddedToWidget();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 gfx::Insets PictureInPictureBrowserFrameView::MirroredFrameBorderInsets()
     const {
   auto border = FrameBorderInsets();
@@ -494,7 +494,7 @@ void PictureInPictureBrowserFrameView::OnMouseEvent(ui
 ///////////////////////////////////////////////////////////////////////////////
 // views::View implementations:
 void PictureInPictureBrowserFrameView::OnPaint(gfx::Canvas* canvas) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     // Draw the PiP window frame borders and shadows, including the top bar
     // background.
@@ -562,7 +562,7 @@ void PictureInPictureBrowserFrameView::UpdateTopBarVie
 }
 
 gfx::Insets PictureInPictureBrowserFrameView::FrameBorderInsets() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (window_frame_provider_) {
     const auto insets = window_frame_provider_->GetFrameThicknessDip();
     const auto tiled_edges = frame()->tiled_edges();
@@ -582,7 +582,7 @@ int PictureInPictureBrowserFrameView::GetTopAreaHeight
   return FrameBorderInsets().top() + kTopControlsHeight;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PictureInPictureBrowserFrameView::SetWindowFrameProvider(
     ui::WindowFrameProvider* window_frame_provider) {
   window_frame_provider_ = window_frame_provider;
