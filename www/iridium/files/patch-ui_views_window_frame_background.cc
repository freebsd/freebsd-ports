--- ui/views/window/frame_background.cc.orig	2017-09-07 02:06:18.851705000 +0200
+++ ui/views/window/frame_background.cc	2017-09-07 02:06:40.569927000 +0200
@@ -173,7 +173,7 @@
 
 void FrameBackground::PaintFrameTopArea(gfx::Canvas* canvas,
                                         const View* view) const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
   params.frame_top_area.use_custom_frame = use_custom_frame_;
