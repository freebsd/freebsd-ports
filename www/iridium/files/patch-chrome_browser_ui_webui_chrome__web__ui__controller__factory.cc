--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -210,7 +210,7 @@
 #include "chrome/browser/ui/webui/chromeos/chrome_url_disabled/chrome_url_disabled_ui.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/webui_js_error/webui_js_error_ui.h"
 #endif
 
@@ -236,17 +236,17 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals_ui.h"
 #endif
 
@@ -403,7 +403,7 @@ bool IsAboutUI(const GURL& url) {
 #if !BUILDFLAG(IS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -667,7 +667,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUIMobileSetupHost)
     return &NewWebUI<ash::cellular_setup::MobileSetupUI>;
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUIWebUIJsErrorHost)
     return &NewWebUI<WebUIJsErrorUI>;
 #endif
@@ -730,7 +730,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
@@ -791,27 +791,27 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   }
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUIConnectorsInternalsHost)
     return &NewWebUI<enterprise_connectors::ConnectorsInternalsUI>;
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (url.host_piece() == chrome::kChromeUIWebAppSettingsHost)
     return &NewWebUI<WebAppSettingsUI>;
 #endif
