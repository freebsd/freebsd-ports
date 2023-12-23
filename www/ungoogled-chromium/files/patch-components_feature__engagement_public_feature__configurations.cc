--- components/feature_engagement/public/feature_configurations.cc.orig	2023-12-23 12:33:28 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -49,7 +49,7 @@ FeatureConfig CreateAlwaysTriggerConfig(const base::Fe
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
@@ -1440,7 +1440,8 @@ absl::optional<FeatureConfig> GetClientSideFeatureConf
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillExternalAccountProfileSuggestionFeature.name ==
       feature->name) {
