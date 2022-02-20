--- ui/base/cursor/cursor_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -80,7 +80,7 @@ void CursorFactory::ObserveThemeChanges() {
 
 void CursorFactory::SetDeviceScaleFactor(float scale) {}
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
