--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -208,7 +208,7 @@ class BrowserOptionsHandler
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
