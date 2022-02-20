--- components/feature_engagement/public/feature_configurations.cc.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -13,7 +13,7 @@ namespace feature_engagement {
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
