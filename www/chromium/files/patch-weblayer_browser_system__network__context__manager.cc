--- weblayer/browser/system_network_context_manager.cc.orig	2022-02-07 13:39:41 UTC
+++ weblayer/browser/system_network_context_manager.cc
@@ -69,7 +69,7 @@ void SystemNetworkContextManager::ConfigureDefaultNetw
   network_context_params->user_agent = user_agent;
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_WIN)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_WIN) || defined(OS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif  // (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) ||
