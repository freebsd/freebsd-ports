--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2017-05-02 19:02:48 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -290,7 +290,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host_piece() == chrome::kChromeUISandboxHost
 #endif
@@ -567,7 +567,7 @@ WebUIFactoryFunction GetWebUIFactoryFunc
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost) {
     return &NewWebUI<ConstrainedWebDialogUI>;
   }
