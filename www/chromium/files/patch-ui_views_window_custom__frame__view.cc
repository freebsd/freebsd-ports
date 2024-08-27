--- ui/views/window/custom_frame_view.cc.orig	2024-08-26 12:06:38 UTC
+++ ui/views/window/custom_frame_view.cc
@@ -268,7 +268,7 @@ int CustomFrameView::CaptionButtonY() const {
   // drawn flush with the screen edge, they still obey Fitts' Law.
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
