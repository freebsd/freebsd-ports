--- src/3rdparty/chromium/chrome/common/webui_url_constants.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/chrome/common/webui_url_constants.cc
@@ -212,21 +212,21 @@ base::span<const base::cstring_view> ChromeURLHosts() 
       kChromeUIAssistantOptInHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       kChromeUIConnectorsInternalsHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       kChromeUIDiscardsHost,
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       kChromeUIWebAppSettingsHost,
 #endif
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
       kChromeUILinuxProxyConfigHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       kChromeUISandboxHost,
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -305,7 +305,7 @@ base::span<const base::cstring_view> ChromeDebugURLs()
        blink::kChromeUIGpuJavaCrashURL,
        kChromeUIJavaCrashURL,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
        kChromeUIWebUIJsErrorURL,
 #endif
        kChromeUIQuitURL,
