--- src/chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc
@@ -100,7 +100,7 @@ MessagingBackendServiceFactory::BuildSer
   // This configuration object allows us to control platform specific behavior.
   MessagingBackendConfiguration configuration;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   configuration.clear_chip_on_tab_selection = false;
 #endif
 
