--- components/feature_engagement/public/feature_constants.cc.orig	2024-02-03 15:42:55 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kUseClientConfigIPH,
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHBatterySaverModeFeature,
              "IPH_BatterySaverMode",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -583,7 +583,7 @@ constexpr base::FeatureParam<int> kDefaultBrowserEligi
     /*default_value=*/365};
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature,
              "IPH_AutofillExternalAccountProfileSuggestion",
@@ -709,7 +709,7 @@ BASE_FEATURE(kIPHScalableIphGamingFeature,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This can be enabled by default, as the DesktopPWAsLinkCapturing flag is
 // needed for the IPH linked to this feature to work, and use-cases to show
 // the IPH are guarded by that flag.
