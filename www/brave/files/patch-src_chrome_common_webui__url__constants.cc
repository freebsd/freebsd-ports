--- src/chrome/common/webui_url_constants.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/common/webui_url_constants.cc
@@ -191,7 +191,7 @@ base::span<const base::cstring_view> Chr
       kChromeUITermsHost,
 #endif
       kChromeUITranslateInternalsHost,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       kChromeUIUpdaterHost,
 #endif
       kChromeUIUsbInternalsHost,
@@ -258,17 +258,17 @@ base::span<const base::cstring_view> Chr
       ash::kChromeUIInternetDetailDialogHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
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
