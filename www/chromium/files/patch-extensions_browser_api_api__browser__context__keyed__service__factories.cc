--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2026-10-18 13:29:39 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -141,7 +141,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   MediaPerceptionAPIManager::GetFactoryInstance();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
