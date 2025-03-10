--- chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc
@@ -83,7 +83,7 @@ MessagingBackendServiceFactory::BuildServiceInstanceFo
   // This configuration object allows us to control platform specific behavior.
   MessagingBackendConfiguration configuration;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   configuration.clear_chip_on_tab_selection = false;
 #endif
 
