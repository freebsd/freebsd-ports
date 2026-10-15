--- cef/libcef/browser/alloy/alloy_browser_host_impl.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/alloy/alloy_browser_host_impl.cc
@@ -80,7 +80,7 @@ const char* kAllowedWebUIHosts[] = {
     chrome::kChromeUIPrintHost,
     content::kChromeUIProcessInternalsHost,
     content::kChromeUIResourcesHost,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     chrome::kChromeUISandboxHost,
 #endif
     content::kChromeUIServiceWorkerInternalsHost,
