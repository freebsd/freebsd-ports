--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -192,11 +192,11 @@
 #include "chrome/browser/ui/webui/welcome/welcome_win10_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/sandbox_internals_ui.h"
 #endif
 
@@ -314,7 +314,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if defined(OS_CHROMEOS)
@@ -588,7 +588,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
 #endif
@@ -641,12 +641,12 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
     return &NewWebUI<CastUI>;
   }
 #endif
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUIDiscardsHost)
     return &NewWebUI<DiscardsUI>;
 #endif
