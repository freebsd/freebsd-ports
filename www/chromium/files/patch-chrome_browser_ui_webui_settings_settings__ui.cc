--- chrome/browser/ui/webui/settings/settings_ui.cc.orig	2021-09-24 18:36:14 UTC
+++ chrome/browser/ui/webui/settings/settings_ui.cc
@@ -139,7 +139,7 @@
 #endif  // defined(USE_NSS_CERTS)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/settings/url_handlers_handler.h"
 #include "chrome/browser/web_applications/components/url_handler_prefs.h"
 #endif
@@ -253,7 +253,7 @@ SettingsUI::SettingsUI(content::WebUI* web_ui)
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   AddSettingsPageUIHandler(std::make_unique<UrlHandlersHandler>(
       g_browser_process->local_state(), profile,
       &GetRegistrarForProfile(profile)));
