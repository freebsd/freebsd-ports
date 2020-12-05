--- components/feature_engagement/public/feature_list.h.orig	2020-11-13 06:36:40 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -126,7 +126,7 @@ DEFINE_VARIATION_PARAM(kIPHDiscoverFeedHeaderFeature,
                        "IPH_DiscoverFeedHeaderMenu");
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
@@ -137,7 +137,7 @@ DEFINE_VARIATION_PARAM(kIPHPasswordsAccountStorageFeat
                        "IPH_PasswordsAccountStorage");
 DEFINE_VARIATION_PARAM(kIPHReopenTabFeature, "IPH_ReopenTab");
 DEFINE_VARIATION_PARAM(kIPHWebUITabStripFeature, "IPH_WebUITabStrip");
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace
@@ -196,7 +196,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHBadgedReadingListFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
         VARIATION_ENTRY(kIPHDiscoverFeedHeaderFeature),
-#elif defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#elif defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
@@ -205,7 +205,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHPasswordsAccountStorageFeature),
         VARIATION_ENTRY(kIPHReopenTabFeature),
         VARIATION_ENTRY(kIPHWebUITabStripFeature),
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 
