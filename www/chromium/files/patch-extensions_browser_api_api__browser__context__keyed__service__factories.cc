--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2025-10-30 15:44:36 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -123,7 +123,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   MediaPerceptionAPIManager::GetFactoryInstance();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
