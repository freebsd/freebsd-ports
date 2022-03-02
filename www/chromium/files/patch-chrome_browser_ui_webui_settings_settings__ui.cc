--- chrome/browser/ui/webui/settings/settings_ui.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/webui/settings/settings_ui.cc
@@ -141,7 +141,7 @@
 #include "chrome/browser/ui/webui/settings/native_certificates_handler.h"
 #endif  // BUILDFLAG(USE_NSS_CERTS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/ui/webui/settings/url_handlers_handler.h"
 #include "chrome/browser/web_applications/web_app_provider.h"
@@ -245,7 +245,7 @@ SettingsUI::SettingsUI(content::WebUI* web_ui)
   AddSettingsPageUIHandler(std::make_unique<ChromeCleanupHandler>(profile));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   if (web_app::WebAppProvider::GetForWebApps(profile) != nullptr) {
     AddSettingsPageUIHandler(std::make_unique<UrlHandlersHandler>(
