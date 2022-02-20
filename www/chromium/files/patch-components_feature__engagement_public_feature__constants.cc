--- components/feature_engagement/public/feature_constants.cc.orig	2022-02-07 13:39:41 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -20,7 +20,7 @@ const base::Feature kIPHDummyFeature{"IPH_Dummy",
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const base::Feature kIPHDesktopSharedHighlightingFeature{
     "IPH_DesktopSharedHighlighting", base::FEATURE_DISABLED_BY_DEFAULT};
 const base::Feature kIPHDesktopTabGroupsNewGroupFeature{
@@ -257,7 +257,7 @@ const base::Feature kIPHDiscoverFeedHeaderFeature{
     "IPH_DiscoverFeedHeaderMenu", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
 const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature{
     "IPH_UpdatedConnectionSecurityIndicators",
