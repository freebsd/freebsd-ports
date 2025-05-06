--- chrome/browser/regional_capabilities/regional_capabilities_service_client.cc.orig	2025-05-05 10:57:53 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_client.cc
@@ -107,7 +107,7 @@ void RegionalCapabilitiesServiceClient::FetchCountryId
       base::android::AttachCurrentThread(),
       reinterpret_cast<intptr_t>(heap_callback.release()));
 }
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RegionalCapabilitiesServiceClient::FetchCountryId(
     CountryIdCallback on_country_id_fetched) {
   std::move(on_country_id_fetched).Run(variations_latest_country_id_);
