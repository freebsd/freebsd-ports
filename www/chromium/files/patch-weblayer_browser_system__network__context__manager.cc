--- weblayer/browser/system_network_context_manager.cc.orig	2020-03-17 10:36:11 UTC
+++ weblayer/browser/system_network_context_manager.cc
@@ -102,7 +102,7 @@ SystemNetworkContextManager::CreateSystemNetworkContex
 
   network_context_params->context_name = std::string("system");
   network_context_params->primary_network_context = true;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif
