--- components/feature_engagement/public/feature_list.h.orig	2020-03-03 18:53:53 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -110,7 +110,7 @@ DEFINE_VARIATION_PARAM(kIPHBadgedTranslateManualTrigge
                        "IPH_BadgedTranslateManualTrigger");
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 DEFINE_VARIATION_PARAM(kIPHFocusModeFeature, "IPH_FocusMode");
 DEFINE_VARIATION_PARAM(kIPHGlobalMediaControls, "IPH_GlobalMediaControls");
@@ -121,7 +121,7 @@ DEFINE_VARIATION_PARAM(kIPHBookmarkFeature, "IPH_Bookm
 DEFINE_VARIATION_PARAM(kIPHIncognitoWindowFeature, "IPH_IncognitoWindow");
 DEFINE_VARIATION_PARAM(kIPHNewTabFeature, "IPH_NewTab");
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace
@@ -170,7 +170,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHNewIncognitoTabTipFeature),
         VARIATION_ENTRY(kIPHBadgedReadingListFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
-#elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
         VARIATION_ENTRY(kIPHFocusModeFeature),
         VARIATION_ENTRY(kIPHGlobalMediaControls),
@@ -181,7 +181,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHIncognitoWindowFeature),
         VARIATION_ENTRY(kIPHNewTabFeature),
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 };
 
