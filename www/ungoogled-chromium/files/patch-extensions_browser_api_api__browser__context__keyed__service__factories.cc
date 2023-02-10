--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2023-01-13 08:56:02 UTC
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -71,7 +71,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
