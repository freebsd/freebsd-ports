--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2019-01-11 19:03:59.864185000 +0100
+++ extensions/browser/browser_context_keyed_service_factories.cc	2019-01-11 19:04:22.204588000 +0100
@@ -85,7 +85,7 @@
 #if defined(OS_CHROMEOS)
   NetworkingConfigServiceFactory::GetInstance();
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
