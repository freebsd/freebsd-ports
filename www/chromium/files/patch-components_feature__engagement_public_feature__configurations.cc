--- components/feature_engagement/public/feature_configurations.cc.orig	2021-07-19 18:45:13 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -12,7 +12,7 @@ namespace feature_engagement {
 
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
@@ -41,7 +41,7 @@ absl::optional<FeatureConfig> GetClientSideFeatureConf
         EventConfig("profile_menu_shown", Comparator(EQUAL, 0), 360, 360);
     return config;
   }
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_ANDROID)
