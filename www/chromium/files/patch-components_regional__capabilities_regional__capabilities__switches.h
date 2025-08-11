--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-08-07 06:57:29 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -26,14 +26,14 @@ inline constexpr char kSearchEngineChoiceCountry[] =
 inline constexpr char kDefaultListCountryOverride[] = "DEFAULT_EEA";
 inline constexpr char kEeaListCountryOverride[] = "EEA_ALL";
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When an invalid `country_codes::CountryId` is stored in prefs and this
 // feature is enabled the pref will be cleared allowing a valid country to be
 // set again.
 BASE_DECLARE_FEATURE(kClearPrefForUnknownCountry);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
