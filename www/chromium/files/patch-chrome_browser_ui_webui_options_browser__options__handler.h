--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -215,7 +215,7 @@ class BrowserOptionsHandler
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
