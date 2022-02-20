--- chrome/browser/ui/webui/settings/settings_ui.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/ui/webui/settings/settings_ui.cc
@@ -140,7 +140,7 @@
 #include "chrome/browser/ui/webui/settings/native_certificates_handler.h"
 #endif  // defined(USE_NSS_CERTS)
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/ui/webui/settings/url_handlers_handler.h"
 #include "chrome/browser/web_applications/web_app_provider.h"
@@ -243,7 +243,7 @@ SettingsUI::SettingsUI(content::WebUI* web_ui)
   AddSettingsPageUIHandler(std::make_unique<ChromeCleanupHandler>(profile));
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   if (web_app::WebAppProvider::GetForWebApps(profile) != nullptr) {
     AddSettingsPageUIHandler(std::make_unique<UrlHandlersHandler>(
