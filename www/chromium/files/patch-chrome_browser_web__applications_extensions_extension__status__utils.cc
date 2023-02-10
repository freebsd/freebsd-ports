--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2023-02-08 09:03:45 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -26,7 +26,7 @@ namespace {
 const char* g_preinstalled_app_for_testing = nullptr;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kMobilityPrintAndDirectPrintIoExtensionIds[] =
     "alhngdkjgnedakdlnamimgfihgkmenbh,gnddkmpjjjcimefninepfmmddpgaaado";
 
@@ -110,7 +110,7 @@ bool ClearExternalExtensionUninstalled(content::Browse
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (!base::FeatureList::IsEnabled(features::kChromeAppsDeprecation))
