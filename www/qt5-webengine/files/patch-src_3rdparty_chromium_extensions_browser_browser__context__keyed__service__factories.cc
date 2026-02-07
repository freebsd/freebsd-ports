--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -106,7 +106,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
