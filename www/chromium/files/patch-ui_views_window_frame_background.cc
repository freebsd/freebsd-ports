--- ui/views/window/frame_background.cc.orig	2018-12-03 21:18:07.000000000 +0100
+++ ui/views/window/frame_background.cc	2018-12-15 21:23:38.516468000 +0100
@@ -122,7 +122,7 @@
                                      const View* view) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
   params.frame_top_area.use_custom_frame = use_custom_frame_;
