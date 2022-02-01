--- chrome/browser/ui/webui/settings/appearance_handler.h.orig	2021-12-14 11:45:00 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.h
@@ -44,7 +44,7 @@ class AppearanceHandler : public SettingsPageUIHandler
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Changes the UI theme of the browser to the system (GTK+) theme.
   void HandleUseSystemTheme(const base::ListValue* args);
 #endif
