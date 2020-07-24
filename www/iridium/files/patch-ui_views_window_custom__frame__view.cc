--- ui/views/window/custom_frame_view.cc.orig	2019-09-09 21:55:47 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -287,7 +287,7 @@ int CustomFrameView::NonClientTopBorderHeight() const 
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
