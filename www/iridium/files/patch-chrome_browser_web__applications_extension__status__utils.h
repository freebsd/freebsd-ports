--- chrome/browser/web_applications/extension_status_utils.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -50,7 +50,7 @@ bool IsExtensionDefaultInstalled(content::BrowserConte
 bool IsExternalExtensionUninstalled(content::BrowserContext* context,
                                     const std::string& extension_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this method returns true, then |extension_id| will not be launchable.
 //
 // The eventual goal is that this method should return true for all hosted apps,
