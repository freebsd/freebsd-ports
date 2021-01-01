--- ui/views/window/frame_background.cc.orig	2020-02-03 21:53:14 UTC
+++ ui/views/window/frame_background.cc
@@ -107,7 +107,7 @@ void FrameBackground::PaintMaximized(gfx::Canvas* canv
                                      const View* view) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
   params.frame_top_area.use_custom_frame = use_custom_frame_;
