--- chrome/browser/ui/views/frame/browser_view.cc.orig	2019-07-24 18:58:12 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1557,7 +1557,7 @@ void BrowserView::UserChangedTheme(BrowserThemeChangeT
   const bool should_use_native_frame = frame_->ShouldUseNativeFrame();
 
   bool must_regenerate_frame;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // GTK and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   must_regenerate_frame = true;
