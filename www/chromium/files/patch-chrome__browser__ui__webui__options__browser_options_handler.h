--- ./chrome/browser/ui/webui/options/browser_options_handler.h.orig	2014-08-12 21:01:37.000000000 +0200
+++ ./chrome/browser/ui/webui/options/browser_options_handler.h	2014-08-13 09:56:57.000000000 +0200
@@ -197,7 +197,8 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
