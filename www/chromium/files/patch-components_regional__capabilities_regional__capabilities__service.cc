--- components/regional_capabilities/regional_capabilities_service.cc.orig	2025-03-05 08:14:56 UTC
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -85,7 +85,7 @@ void RegionalCapabilitiesService::InitializeCountryIdC
       base::UmaHistogramEnumeration(kUnknownCountryIdStored,
                                     UnknownCountryIdStored::kValidCountryId);
     } else {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (base::FeatureList::IsEnabled(switches::kClearPrefForUnknownCountry)) {
         profile_prefs_->ClearPref(country_codes::kCountryIDAtInstall);
         country_id.reset();
