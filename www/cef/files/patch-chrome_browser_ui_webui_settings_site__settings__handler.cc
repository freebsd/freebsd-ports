--- chrome/browser/ui/webui/settings/site_settings_handler.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/settings/site_settings_handler.cc
@@ -128,7 +128,7 @@
 #include "url/url_constants.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -2100,7 +2100,7 @@ void SiteSettingsHandler::SendZoomLevels() {
   base::ListValue zoom_levels_exceptions;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Show any non-default Isolated Web App zoom levels at the top of the page.
   auto* web_app_provider = web_app::WebAppProvider::GetForWebApps(profile_);
   if (web_app_provider) {
@@ -2202,7 +2202,7 @@ void SiteSettingsHandler::HandleRemoveZoomLevel(const 
   GURL url(host_or_spec);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.is_valid() && url.GetScheme() == webapps::kIsolatedAppScheme) {
     base::expected<web_app::IsolatedWebAppUrlInfo, std::string> iwa_url_info =
         web_app::IsolatedWebAppUrlInfo::Create(url);
