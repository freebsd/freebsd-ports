--- ui/views/window/custom_frame_view.cc.orig	2021-12-14 11:45:40 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -265,7 +265,7 @@ int CustomFrameView::CaptionButtonY() const {
   // drawn flush with the screen edge, they still obey Fitts' Law.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
