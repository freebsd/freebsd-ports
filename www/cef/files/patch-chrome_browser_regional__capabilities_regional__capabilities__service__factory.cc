--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc
@@ -21,7 +21,7 @@
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_chromeos.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_linux.h"
 #endif
 
@@ -36,7 +36,7 @@ CreateRegionalCapabilitiesServiceClient() {
 #elif BUILDFLAG(IS_CHROMEOS)
   return std::make_unique<RegionalCapabilitiesServiceClientChromeOS>(
       g_browser_process->variations_service());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<RegionalCapabilitiesServiceClientLinux>(
       g_browser_process->variations_service());
 #else
@@ -61,7 +61,7 @@ RegionalCapabilitiesServiceFactory::GetInstance() {
   return instance.get();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesServiceFactory::
     IsInSearchEngineChoiceScreenRegionForSystemProfile(Profile* profile) {
