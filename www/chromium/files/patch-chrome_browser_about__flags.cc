--- chrome/browser/about_flags.cc.orig	2021-09-24 04:25:57 UTC
+++ chrome/browser/about_flags.cc
@@ -195,7 +195,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -966,7 +966,7 @@ const FeatureEntry::FeatureVariation kMemoriesVariatio
      base::size(kMemoryVariationRemote), nullptr},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
@@ -1164,7 +1164,7 @@ const FeatureEntry::FeatureVariation kOmniboxBookmarkP
     {"Dynamic Replace URL (Title - Path|URL)",
      kOmniboxBookmarkPathsDynamicReplaceUrl,
      base::size(kOmniboxBookmarkPathsDynamicReplaceUrl), nullptr}};
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 const FeatureEntry::FeatureVariation
@@ -3131,7 +3131,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kDeprecateLowUsageCodecs)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3149,7 +3149,7 @@ const FeatureEntry kFeatureEntries[] = {
         kOsMac | kOsWin | kOsCrOS | kOsAndroid | kOsLinux,
         SINGLE_DISABLE_VALUE_TYPE(switches::kDisableAcceleratedVideoDecode),
     },
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     {
         "disable-accelerated-video-encode",
         flag_descriptions::kAcceleratedVideoEncodeName,
@@ -3511,7 +3511,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3521,7 +3521,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX
+#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -4326,7 +4326,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
@@ -4438,7 +4438,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxPreserveLongerShortcutsTextName,
      flag_descriptions::kOmniboxPreserveLongerShortcutsTextDescription,
      kOsDesktop, FEATURE_VALUE_TYPE(omnibox::kPreserveLongerShortcutsText)},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -4707,12 +4707,12 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReaderModeInCCT)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"webui-feedback", flag_descriptions::kWebuiFeedbackName,
      flag_descriptions::kWebuiFeedbackDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebUIFeedback)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
@@ -5322,7 +5322,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingSendViaSyncDescription, kOsAll,
      FEATURE_VALUE_TYPE(kSharingSendViaSync)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"sharing-hub-desktop-app-menu",
      flag_descriptions::kSharingHubDesktopAppMenuName,
      flag_descriptions::kSharingHubDesktopAppMenuDescription, kOsDesktop,
@@ -5331,7 +5331,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingHubDesktopOmniboxName,
      flag_descriptions::kSharingHubDesktopOmniboxDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(sharing_hub::kSharingHubDesktopOmnibox)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
     {"ash-enable-pip-rounded-corners",
@@ -5805,7 +5805,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kMouseSubframeNoImplicitCaptureDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
@@ -5846,7 +5846,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalMediaControlsOverlayControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsOverlayControls)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"safety-tips", flag_descriptions::kSafetyTipName,
@@ -6648,7 +6648,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kIncognitoReauthenticationForAndroid)},
 #endif
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
@@ -6667,7 +6667,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kInheritNativeThemeFromParentWidgetDescription,
      kOsDesktop,
      FEATURE_VALUE_TYPE(views::features::kInheritNativeThemeFromParentWidget)},
-#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) ||
+#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
     {"content-settings-redesign",
@@ -6778,7 +6778,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(language::kForceAppLanguagePrompt)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -6805,8 +6805,8 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSyncAutofillWalletOfferDataDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncAutofillWalletOfferData)},
 
-#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-     defined(OS_CHROMEOS)) &&                                   \
+#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
+     defined(OS_CHROMEOS)) &&                                                      \
     BUILDFLAG(ENABLE_PRINTING)
     {"enable-oop-print-drivers", flag_descriptions::kEnableOopPrintDriversName,
      flag_descriptions::kEnableOopPrintDriversDescription, kOsDesktop,
@@ -7091,7 +7091,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kVaapiVp9kSVCHWEncoding)},
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {
         "ui-debug-tools",
@@ -7181,7 +7181,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(metrics::structured::kBluetoothSessionizedMetrics)},
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     {"use-ozone-platform", flag_descriptions::kUseOzonePlatformName,
      flag_descriptions::kUseOzonePlatformDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kUseOzonePlatform)},
@@ -7224,7 +7224,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chromeos::features::kLauncherAppSort)},
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-desktop-pwas-app-icon-shortcuts-menu-ui",
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIName,
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIDescription,
@@ -7487,7 +7487,7 @@ const FeatureEntry kFeatureEntries[] = {
          ash::features::kHoldingSpaceInProgressDownloadsIntegration)},
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC) || (defined(OS_ANDROID))
     {"omnibox-updated-connection-security-indicators",
      flag_descriptions::kOmniboxUpdatedConnectionSecurityIndicatorsName,
