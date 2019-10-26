--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -93,7 +93,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
