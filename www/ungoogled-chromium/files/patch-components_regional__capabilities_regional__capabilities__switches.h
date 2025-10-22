--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-10-21 16:57:35 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -47,7 +47,7 @@ BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoO
 BASE_DECLARE_FEATURE(kResolveRegionalCapabilitiesFromDevice);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
