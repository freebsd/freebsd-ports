--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2016-05-11 19:02:17 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -204,7 +204,7 @@ class BrowserOptionsHandler
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
