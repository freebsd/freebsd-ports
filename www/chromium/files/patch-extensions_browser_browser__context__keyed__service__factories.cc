--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2019-04-30 22:22:49 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -84,7 +84,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
