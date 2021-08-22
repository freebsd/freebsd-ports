--- chrome/browser/about_flags.cc.orig	2021-07-21 14:11:02 UTC
+++ chrome/browser/about_flags.cc
@@ -192,7 +192,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -992,7 +992,7 @@ const FeatureEntry::FeatureVariation kMemoriesVariatio
     nullptr,
 }};
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
@@ -1263,7 +1263,7 @@ const FeatureEntry::FeatureVariation kOmniboxBookmarkP
         nullptr,
     },
 };
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 const FeatureEntry::FeatureVariation
@@ -3151,7 +3151,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kDeprecateLowUsageCodecs)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3169,7 +3169,7 @@ const FeatureEntry kFeatureEntries[] = {
         kOsMac | kOsWin | kOsCrOS | kOsAndroid | kOsLinux,
         SINGLE_DISABLE_VALUE_TYPE(switches::kDisableAcceleratedVideoDecode),
     },
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     {
         "disable-accelerated-video-encode",
         flag_descriptions::kAcceleratedVideoEncodeName,
@@ -3510,7 +3510,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3520,7 +3520,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX
+#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -4346,7 +4346,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
@@ -4443,7 +4443,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxKeywordSpaceTriggeringSettingName,
      flag_descriptions::kOmniboxKeywordSpaceTriggeringSettingDescription,
      kOsDesktop, FEATURE_VALUE_TYPE(omnibox::kKeywordSpaceTriggeringSetting)},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -4721,7 +4721,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReaderModeInCCT)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
@@ -4732,7 +4732,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"webui-feedback", flag_descriptions::kWebuiFeedbackName,
      flag_descriptions::kWebuiFeedbackDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebUIFeedback)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
@@ -5373,7 +5373,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kSharingDeviceExpirationVariations,
                                     "SharingDeviceExpiration")},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"sharing-hub-desktop-app-menu",
      flag_descriptions::kSharingHubDesktopAppMenuName,
      flag_descriptions::kSharingHubDesktopAppMenuDescription, kOsDesktop,
@@ -5382,7 +5382,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingHubDesktopOmniboxName,
      flag_descriptions::kSharingHubDesktopOmniboxDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(sharing_hub::kSharingHubDesktopOmnibox)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
     {"ash-enable-pip-rounded-corners",
@@ -5856,7 +5856,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kMouseSubframeNoImplicitCaptureDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
@@ -5897,7 +5897,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalMediaControlsOverlayControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsOverlayControls)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
@@ -6089,7 +6089,7 @@ const FeatureEntry kFeatureEntries[] = {
          kPasswordsAccountStorageVariations,
          "ButterForPasswords")},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"passwords-account-storage-iph",
      flag_descriptions::kEnablePasswordsAccountStorageIPHName,
@@ -6097,7 +6097,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHPasswordsAccountStorageFeature)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"autofill-always-return-cloud-tokenized-card",
@@ -6701,7 +6701,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kIncognitoBrandConsistencyForAndroid)},
 #endif
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
@@ -6806,7 +6806,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(language::kDetailedLanguageSettings)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -6835,8 +6835,8 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSyncAutofillWalletOfferDataDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncAutofillWalletOfferData)},
 
-#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-     defined(OS_CHROMEOS)) &&                                   \
+#if (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
+     defined(OS_CHROMEOS)) &&                                                      \
     BUILDFLAG(ENABLE_PRINTING)
     {"enable-oop-print-drivers", flag_descriptions::kEnableOopPrintDriversName,
      flag_descriptions::kEnableOopPrintDriversDescription, kOsDesktop,
@@ -6855,14 +6855,14 @@ const FeatureEntry kFeatureEntries[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {"enable-ephemeral-guest-profiles-on-desktop",
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopName,
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopDescription,
      kOsWin | kOsLinux | kOsMac,
      FEATURE_VALUE_TYPE(features::kEnableEphemeralGuestProfilesOnDesktop)},
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_MAC)
 
 #if defined(OS_ANDROID)
@@ -7148,7 +7148,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kVaapiAV1Decoder)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {
         "ui-debug-tools",
@@ -7225,7 +7225,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(metrics::structured::kBluetoothSessionizedMetrics)},
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     {"use-ozone-platform", flag_descriptions::kUseOzonePlatformName,
      flag_descriptions::kUseOzonePlatformDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kUseOzonePlatform)},
