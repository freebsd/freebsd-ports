--- ui/views/window/default_frame_view.cc.orig	2025-09-10 13:22:16 UTC
+++ ui/views/window/default_frame_view.cc
@@ -285,7 +285,7 @@ int DefaultFrameView::NonClientTopBorderHeight() const
 int DefaultFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
