--- components/feature_engagement/public/feature_configurations.cc.orig	2024-04-23 07:42:17 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -94,7 +94,7 @@ std::optional<FeatureConfig> CreateNewUserGestureInPro
 
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   // The IPH bubble for link capturing has a trigger set to ANY so that it
   // always shows up. The per app specific guardrails are independently stored
@@ -113,7 +113,7 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     std::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
@@ -1393,7 +1393,8 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillExternalAccountProfileSuggestionFeature.name ==
       feature->name) {
@@ -1965,7 +1966,7 @@ std::optional<FeatureConfig> GetClientSideFeatureConfi
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (kIPHDeepScanPromptRemovalFeature.name == feature->name) {
     std::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
