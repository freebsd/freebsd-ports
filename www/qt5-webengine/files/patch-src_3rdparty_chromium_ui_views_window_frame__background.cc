--- src/3rdparty/chromium/ui/views/window/frame_background.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/window/frame_background.cc
@@ -99,7 +99,7 @@ void FrameBackground::PaintMaximized(gfx::Canvas* canv
                                      const View* view) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
