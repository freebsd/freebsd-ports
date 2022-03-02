--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2022-02-28 16:54:41 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -91,7 +91,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
