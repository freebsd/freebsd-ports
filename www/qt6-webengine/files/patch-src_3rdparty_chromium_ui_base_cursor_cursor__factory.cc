--- src/3rdparty/chromium/ui/base/cursor/cursor_factory.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/ui/base/cursor/cursor_factory.cc
@@ -89,7 +89,7 @@ void CursorFactory::ObserveThemeChanges() {
 
 void CursorFactory::SetDeviceScaleFactor(float scale) {}
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
