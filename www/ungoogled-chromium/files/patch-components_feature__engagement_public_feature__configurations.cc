--- components/feature_engagement/public/feature_configurations.cc.orig	2024-08-26 14:40:28 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -99,7 +99,7 @@ std::optional<FeatureConfig> CreateNewUserGestureInPro
 
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   // The IPH bubble for link capturing has a trigger set to ANY so that it
   // always shows up. The per app specific guardrails are independently stored
@@ -118,7 +118,7 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsManagementBubbleAfterSaveFeature.name == feature->name) {
     std::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
@@ -1599,7 +1599,8 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillCreditCardBenefitFeature.name == feature->name) {
     // Credit card benefit IPH is shown:
