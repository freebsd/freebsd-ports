--- ui/base/cursor/cursor_factory.cc.orig	2024-11-14 07:57:23 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -96,7 +96,7 @@ void CursorFactory::ObserveThemeChanges() {
   NOTIMPLEMENTED();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
