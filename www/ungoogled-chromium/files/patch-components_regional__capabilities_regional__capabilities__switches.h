--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-11-01 06:40:37 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -53,7 +53,7 @@ BASE_DECLARE_FEATURE(kRestrictLegacySearchEnginePromoO
 BASE_DECLARE_FEATURE(kResolveRegionalCapabilitiesFromDevice);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
