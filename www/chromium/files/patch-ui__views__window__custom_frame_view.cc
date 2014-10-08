--- ui/views/window/custom_frame_view.cc.orig	2014-10-06 09:19:47.000000000 +0200
+++ ui/views/window/custom_frame_view.cc	2014-10-06 09:20:31.000000000 +0200
@@ -281,7 +281,7 @@
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
