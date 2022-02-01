--- chrome/browser/ui/webui/settings/settings_ui.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/webui/settings/settings_ui.cc
@@ -138,7 +138,7 @@
 #endif  // defined(USE_NSS_CERTS)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/settings/url_handlers_handler.h"
 #endif
 
@@ -239,7 +239,7 @@ SettingsUI::SettingsUI(content::WebUI* web_ui)
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   AddSettingsPageUIHandler(std::make_unique<UrlHandlersHandler>(
       g_browser_process->local_state(), profile));
 #endif
