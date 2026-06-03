--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-04-09 06:05:42 UTC
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -413,7 +413,7 @@ bool RegionalCapabilitiesService::IsInSearchEngineChoi
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInSearchEngineChoiceScreenRegion(
     Client& client) {
