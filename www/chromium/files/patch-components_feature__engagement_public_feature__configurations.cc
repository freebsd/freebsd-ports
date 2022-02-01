--- components/feature_engagement/public/feature_configurations.cc.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -12,7 +12,7 @@ namespace feature_engagement {
 
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
@@ -87,7 +87,7 @@ absl::optional<FeatureConfig> GetClientSideFeatureConf
                     Comparator(EQUAL, 0), 7, 360));
     return config;
   }
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_ANDROID)
