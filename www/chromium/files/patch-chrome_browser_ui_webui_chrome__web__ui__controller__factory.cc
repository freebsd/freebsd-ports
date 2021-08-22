--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2021-07-19 18:45:10 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -31,7 +31,9 @@
 #include "chrome/browser/ui/webui/bluetooth_internals/bluetooth_internals_ui.h"
 #include "chrome/browser/ui/webui/components/components_ui.h"
 #include "chrome/browser/ui/webui/constrained_web_dialog_ui.h"
+#if !defined(OS_BSD)
 #include "chrome/browser/ui/webui/crashes_ui.h"
+#endif
 #include "chrome/browser/ui/webui/device_log_ui.h"
 #include "chrome/browser/ui/webui/domain_reliability_internals_ui.h"
 #include "chrome/browser/ui/webui/download_internals/download_internals_ui.h"
@@ -280,12 +282,12 @@
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
@@ -523,7 +525,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -572,8 +574,10 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
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
@@ -969,7 +973,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || defined(OS_BSD) || \
     defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
@@ -1019,13 +1023,13 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
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
     defined(OS_CHROMEOS)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
@@ -1033,7 +1037,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   if (url.host_piece() == chrome::kChromeUIBrowserSwitchHost)
     return &NewWebUI<BrowserSwitchUI>;
 #endif
@@ -1221,8 +1225,10 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
     return ConflictsUI::GetFaviconResourceBytes(scale_factor);
 #endif
 
+#if !defined(OS_BSD)
   if (page_url.host_piece() == chrome::kChromeUICrashesHost)
     return CrashesUI::GetFaviconResourceBytes(scale_factor);
+#endif
 
   if (page_url.host_piece() == chrome::kChromeUIFlagsHost)
     return FlagsUI::GetFaviconResourceBytes(scale_factor);
