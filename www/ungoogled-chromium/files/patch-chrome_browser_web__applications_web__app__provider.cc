--- chrome/browser/web_applications/web_app_provider.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/browser/web_applications/web_app_provider.cc
@@ -283,7 +283,7 @@ void WebAppProvider::CreateSubsystems(Profile* profile
         protocol_handler_manager.get());
 
     std::unique_ptr<UrlHandlerManager> url_handler_manager;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     url_handler_manager = std::make_unique<UrlHandlerManagerImpl>(profile);
 #endif
 
