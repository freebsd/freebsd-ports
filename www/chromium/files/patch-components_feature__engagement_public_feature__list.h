--- components/feature_engagement/public/feature_list.h.orig	2021-07-19 18:45:13 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -167,7 +167,7 @@ DEFINE_VARIATION_PARAM(kIPHDiscoverFeedHeaderFeature,
                        "IPH_DiscoverFeedHeaderMenu");
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
@@ -186,7 +186,7 @@ DEFINE_VARIATION_PARAM(kIPHDesktopPwaInstallFeature, "
 DEFINE_VARIATION_PARAM(kIPHProfileSwitchFeature, "IPH_ProfileSwitch");
 DEFINE_VARIATION_PARAM(kIPHUpdatedConnectionSecurityIndicatorsFeature,
                        "IPH_UpdatedConnectionSecurityIndicators");
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace
@@ -271,7 +271,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHBadgedReadingListFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
         VARIATION_ENTRY(kIPHDiscoverFeedHeaderFeature),
-#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
@@ -285,7 +285,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHDesktopPwaInstallFeature),
         VARIATION_ENTRY(kIPHProfileSwitchFeature),
         VARIATION_ENTRY(kIPHUpdatedConnectionSecurityIndicatorsFeature),
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 
