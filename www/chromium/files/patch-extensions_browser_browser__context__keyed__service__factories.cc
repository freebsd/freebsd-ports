--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2020-11-13 06:36:43 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -96,7 +96,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
