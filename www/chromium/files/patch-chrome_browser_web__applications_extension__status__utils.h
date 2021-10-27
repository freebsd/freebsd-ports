--- chrome/browser/web_applications/extension_status_utils.h.orig	2021-09-24 18:36:53 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -37,7 +37,7 @@ bool IsExtensionForceInstalled(content::BrowserContext
 bool IsExternalExtensionUninstalled(content::BrowserContext* context,
                                     const std::string& extension_id);
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // Returns whether |extension_id| is a Chrome App and should be blocked by the
 // Chrome Apps Deprecation. Policy installed Chrome Apps are still allowed, and
 // all apps are allowed if the deprecation feature flag is not enabled.
