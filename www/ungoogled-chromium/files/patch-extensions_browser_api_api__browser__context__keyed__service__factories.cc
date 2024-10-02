--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2024-10-01 07:26:23 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -111,7 +111,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
 #endif
   MessageService::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
