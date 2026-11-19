--- components/feature_engagement/public/feature_configurations.cc.orig	2026-11-19 12:25:27 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -106,7 +106,7 @@ std::optional<FeatureConfig> CreateNewUserGestureInPro
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsManagementBubbleAfterSaveFeature.name == feature->name) {
     FeatureConfig config;
     config.valid = true;
@@ -2662,7 +2662,7 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillCreditCardBenefitFeature.name == feature->name) {
     // The credit card benefit IPH appears up to three times over 10 years and
