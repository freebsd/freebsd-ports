--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -292,13 +292,13 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if defined(OS_CHROMEOS)
           || url.host_piece() == chrome::kChromeUIOSCreditsHost
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUIDiscardsHost
 #endif
           );  // NOLINT
@@ -568,7 +568,7 @@ WebUIFactoryFunction GetWebUIFactoryFunction(WebUI* we
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost) {
     return &NewWebUI<ConstrainedWebDialogUI>;
   }
