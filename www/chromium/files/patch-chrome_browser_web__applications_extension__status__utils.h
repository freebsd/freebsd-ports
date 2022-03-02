--- chrome/browser/web_applications/extension_status_utils.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -42,7 +42,7 @@ bool IsExtensionDefaultInstalled(content::BrowserConte
 bool IsExternalExtensionUninstalled(content::BrowserContext* context,
                                     const std::string& extension_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns whether |extension_id| is a Chrome App and should be blocked by the
 // Chrome Apps Deprecation. Policy installed Chrome Apps are still allowed, and
 // all apps are allowed if the deprecation feature flag is not enabled.
