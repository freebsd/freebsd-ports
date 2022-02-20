--- chrome/browser/web_applications/web_app_provider.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/web_applications/web_app_provider.cc
@@ -276,7 +276,7 @@ void WebAppProvider::CreateSubsystems(Profile* profile
         protocol_handler_manager.get());
 
     std::unique_ptr<UrlHandlerManager> url_handler_manager;
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
     url_handler_manager = std::make_unique<UrlHandlerManagerImpl>(profile);
 #endif
