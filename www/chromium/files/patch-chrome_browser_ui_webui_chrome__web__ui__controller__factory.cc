--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -30,7 +30,9 @@
 #include "chrome/browser/ui/webui/bluetooth_internals/bluetooth_internals_ui.h"
 #include "chrome/browser/ui/webui/components/components_ui.h"
 #include "chrome/browser/ui/webui/constrained_web_dialog_ui.h"
+#if !defined(OS_BSD)
 #include "chrome/browser/ui/webui/crashes_ui.h"
+#endif
 #include "chrome/browser/ui/webui/device_log_ui.h"
 #include "chrome/browser/ui/webui/domain_reliability_internals_ui.h"
 #include "chrome/browser/ui/webui/download_internals/download_internals_ui.h"
@@ -294,17 +296,17 @@
 #include "chrome/browser/ui/webui/conflicts/conflicts_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_ASH)
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals_ui.h"
 #endif
@@ -568,7 +570,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -617,8 +619,10 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
     return &NewWebUI<ComponentsUI>;
   if (url.spec() == chrome::kChromeUIConstrainedHTMLTestURL)
     return &NewWebUI<ConstrainedWebDialogUI>;
+#if !defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUICrashesHost)
     return &NewWebUI<CrashesUI>;
+#endif
   if (url.host_piece() == chrome::kChromeUIDeviceLogHost)
     return &NewWebUI<chromeos::DeviceLogUI>;
   if (url.host_piece() == chrome::kChromeUIDomainReliabilityInternalsHost)
@@ -1027,7 +1031,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || defined(OS_BSD) || \
     defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
@@ -1081,23 +1085,23 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
     return &NewWebUI<media_router::MediaRouterInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_ASH)
   if (url.host_piece() == chrome::kChromeUIConnectorsInternalsHost)
     return &NewWebUI<enterprise_connectors::ConnectorsInternalsUI>;
 #endif
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
 #endif
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
@@ -1290,8 +1294,10 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
     return ConflictsUI::GetFaviconResourceBytes(scale_factor);
 #endif
 
+#if !defined(OS_BSD)
   if (page_url.host_piece() == chrome::kChromeUICrashesHost)
     return CrashesUI::GetFaviconResourceBytes(scale_factor);
+#endif
 
   if (page_url.host_piece() == chrome::kChromeUIFlagsHost)
     return FlagsUI::GetFaviconResourceBytes(scale_factor);
