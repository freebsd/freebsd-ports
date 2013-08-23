--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2013-08-23 16:36:30.000000000 +0300
+++ chrome/browser/ui/webui/options/browser_options_handler.h	2013-08-23 16:54:38.000000000 +0300
@@ -194,7 +194,7 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
