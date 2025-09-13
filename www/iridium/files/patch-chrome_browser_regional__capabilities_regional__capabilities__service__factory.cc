--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc
@@ -21,7 +21,7 @@
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_chromeos.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_linux.h"
 #endif
 
@@ -72,7 +72,7 @@ RegionalCapabilitiesServiceFactory::BuildServiceInstan
 #elif BUILDFLAG(IS_CHROMEOS)
       std::make_unique<RegionalCapabilitiesServiceClientChromeOS>(
           g_browser_process->variations_service());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       std::make_unique<RegionalCapabilitiesServiceClientLinux>(
           g_browser_process->variations_service());
 #else
