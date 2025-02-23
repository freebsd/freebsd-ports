--- components/search_engines/search_engines_switches.cc.orig	2025-02-22 18:06:53 UTC
+++ components/search_engines/search_engines_switches.cc
@@ -107,7 +107,7 @@ const base::FeatureParam<bool> kReconcileWithAllKnownE
     "reconcile_with_all_known_engines",
     false);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SEARCH_ENGINES_SWITCHES)
 BASE_FEATURE(kClearPrefForUnknownCountry,
              "ClearCountryPrefForStoredUnknownCountry",
