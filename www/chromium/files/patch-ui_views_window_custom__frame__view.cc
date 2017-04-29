--- ui/views/window/custom_frame_view.cc.orig	2017-04-19 19:06:55 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -302,7 +302,7 @@ int CustomFrameView::NonClientTopBorderH
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
