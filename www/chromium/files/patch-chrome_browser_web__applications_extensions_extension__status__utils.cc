--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -88,7 +88,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (!base::FeatureList::IsEnabled(features::kChromeAppsDeprecation))
