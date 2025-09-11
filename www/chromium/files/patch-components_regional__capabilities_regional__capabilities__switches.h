--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-09-06 10:01:20 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -33,7 +33,7 @@ inline constexpr char kEeaListCountryOverride[] = "EEA
 BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoOverlap);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
