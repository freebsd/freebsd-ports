--- src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -126,7 +126,7 @@ void EnsureApiBrowserContextKeyedServiceFactoriesBuilt
 #endif
   MessageService::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
