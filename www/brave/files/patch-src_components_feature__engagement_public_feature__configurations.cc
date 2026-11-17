--- src/components/feature_engagement/public/feature_configurations.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/feature_engagement/public/feature_configurations.cc
@@ -102,7 +102,7 @@ std::optional<FeatureConfig> CreateNewUs
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsManagementBubbleAfterSaveFeature.name == feature->name) {
     FeatureConfig config;
     config.valid = true;
@@ -2406,7 +2406,7 @@ std::optional<FeatureConfig> GetClientSi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillCreditCardBenefitFeature.name == feature->name) {
     // The credit card benefit IPH appears up to three times over 10 years and
