--- src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -132,7 +132,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
 #endif
   MessageService::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
