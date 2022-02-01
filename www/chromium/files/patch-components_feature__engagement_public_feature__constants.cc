--- components/feature_engagement/public/feature_constants.cc.orig	2021-12-31 00:57:29 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -19,7 +19,7 @@ const base::Feature kUseClientConfigIPH{"UseClientConf
 const base::Feature kIPHDummyFeature{"IPH_Dummy",
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 const base::Feature kIPHDesktopSharedHighlightingFeature{
     "IPH_DesktopSharedHighlighting", base::FEATURE_DISABLED_BY_DEFAULT};
@@ -53,7 +53,7 @@ const base::Feature kIPHDesktopPwaInstallFeature{
     "IPH_DesktopPwaInstall", base::FEATURE_ENABLED_BY_DEFAULT};
 const base::Feature kIPHProfileSwitchFeature{"IPH_ProfileSwitch",
                                              base::FEATURE_ENABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_ANDROID)
@@ -232,12 +232,12 @@ const base::Feature kIPHDiscoverFeedHeaderFeature{
     "IPH_DiscoverFeedHeaderMenu", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
 const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature{
     "IPH_UpdatedConnectionSecurityIndicators",
     base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
 
 }  // namespace feature_engagement
