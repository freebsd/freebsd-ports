--- components/regional_capabilities/regional_capabilities_service.h.orig	2026-04-15 11:25:12 UTC
+++ components/regional_capabilities/regional_capabilities_service.h
@@ -117,7 +117,7 @@ class RegionalCapabilitiesService : public KeyedServic
   static bool IsInSearchEngineChoiceScreenRegion(
       const country_codes::CountryId& tested_country_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the country obtained from the client is associated with
   // a region in which we can show a search engine choice screen.
   //
