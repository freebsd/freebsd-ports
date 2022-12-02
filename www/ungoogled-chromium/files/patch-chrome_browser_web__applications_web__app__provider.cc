--- chrome/browser/web_applications/web_app_provider.cc.orig	2022-12-02 17:56:32 UTC
+++ chrome/browser/web_applications/web_app_provider.cc
@@ -277,7 +277,7 @@ void WebAppProvider::CreateSubsystems(Profile* profile
         protocol_handler_manager.get());
 
     std::unique_ptr<UrlHandlerManager> url_handler_manager;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
     url_handler_manager = std::make_unique<UrlHandlerManagerImpl>(profile);
 #endif
