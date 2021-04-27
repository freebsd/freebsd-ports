--- chrome/browser/web_applications/web_app_provider.cc.orig	2021-04-22 08:00:21 UTC
+++ chrome/browser/web_applications/web_app_provider.cc
@@ -236,7 +236,7 @@ void WebAppProvider::CreateWebAppsSubsystems(Profile* 
 
     std::unique_ptr<UrlHandlerManager> url_handler_manager = nullptr;
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
     url_handler_manager = std::make_unique<UrlHandlerManagerImpl>(profile);
 #endif
 
