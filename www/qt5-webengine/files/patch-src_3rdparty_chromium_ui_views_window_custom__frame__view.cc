--- src/3rdparty/chromium/ui/views/window/custom_frame_view.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/window/custom_frame_view.cc
@@ -261,7 +261,7 @@ int CustomFrameView::CaptionButtonY() const {
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
