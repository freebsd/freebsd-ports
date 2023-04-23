--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -99,7 +99,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
 #endif // !defined(TOOLKIT_QT)
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
