--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2021-09-24 18:37:10 UTC
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -75,7 +75,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   auto* registry = ExtensionRegistry::Get(context);
