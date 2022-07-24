--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2022-07-22 17:30:31 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -88,7 +88,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
