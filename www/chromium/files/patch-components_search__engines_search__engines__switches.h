--- components/search_engines/search_engines_switches.h.orig	2025-02-19 07:43:18 UTC
+++ components/search_engines/search_engines_switches.h
@@ -113,7 +113,7 @@ BASE_DECLARE_FEATURE(kTemplateUrlReconciliation);
 COMPONENT_EXPORT(SEARCH_ENGINES_SWITCHES)
 extern const base::FeatureParam<bool> kReconcileWithAllKnownEngines;
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When the `country_codes::kCountryIDUnknown` is stored in prefs and this
 // feature is enabled the pref will be cleared allowing a valid country to be
 // set again.
