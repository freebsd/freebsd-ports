--- chrome/browser/ui/webui/settings/appearance_handler.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.h
@@ -35,7 +35,7 @@ class AppearanceHandler : public Setting
   // Changes the UI theme of the browser to the default theme.
   void HandleUseDefaultTheme(const base::ListValue* args);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // Changes the UI theme of the browser to the system (GTK+) theme.
   void HandleUseSystemTheme(const base::ListValue* args);
 #endif
