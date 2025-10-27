--- components/feature_engagement/public/feature_configurations.cc.orig	2025-10-21 16:57:35 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -95,7 +95,7 @@ std::optional<FeatureConfig> CreateNewUserGestureInPro
 
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   // The IPH bubble for link capturing has a trigger set to ANY so that it
   // always shows up. The per app specific guardrails are independently stored
@@ -114,7 +114,7 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsManagementBubbleAfterSaveFeature.name == feature->name) {
     FeatureConfig config;
     config.valid = true;
@@ -1979,7 +1979,8 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillCreditCardBenefitFeature.name == feature->name) {
     // The credit card benefit IPH appears up to three times over 10 years and
