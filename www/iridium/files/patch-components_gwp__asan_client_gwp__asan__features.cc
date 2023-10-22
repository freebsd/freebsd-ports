--- components/gwp_asan/client/gwp_asan_features.cc.orig	2023-11-22 14:00:11 UTC
+++ components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
 constexpr base::FeatureState kDefaultEnabled =
