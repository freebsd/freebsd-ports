--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2023-05-20 06:21:07 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -96,7 +96,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   MessageService::GetFactoryInstance();
   MessagingAPIMessageFilter::EnsureAssociatedFactoryBuilt();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
