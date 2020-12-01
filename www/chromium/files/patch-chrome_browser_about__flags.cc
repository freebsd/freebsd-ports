--- chrome/browser/about_flags.cc.orig	2020-11-16 14:15:55 UTC
+++ chrome/browser/about_flags.cc
@@ -881,7 +881,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
@@ -1231,7 +1231,7 @@ const FeatureEntry::FeatureVariation kOmniboxBookmarkP
     },
 };
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 const FeatureEntry::FeatureParam kOmniboxOnFocusSuggestionsParamSERP[] = {
@@ -2857,7 +2857,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kSystemTrayMicGainSetting)},
 #endif  // OS_CHROMEOS
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -2873,7 +2873,7 @@ const FeatureEntry kFeatureEntries[] = {
         kOsMac | kOsWin | kOsCrOS | kOsAndroid,
         SINGLE_DISABLE_VALUE_TYPE(switches::kDisableAcceleratedVideoDecode),
     },
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
     {
         "disable-accelerated-video-encode",
         flag_descriptions::kAcceleratedVideoEncodeName,
@@ -2979,13 +2979,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kForceEnableDevicesPageName,
      flag_descriptions::kForceEnableDevicesPageDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kForceEnableDevicesPage)},
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl2-compute-context",
      flag_descriptions::kWebGL2ComputeContextName,
      flag_descriptions::kWebGL2ComputeContextDescription,
      kOsWin | kOsLinux | kOsCrOS,
      SINGLE_VALUE_TYPE(switches::kEnableWebGL2ComputeContext)},
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl-draft-extensions",
      flag_descriptions::kWebglDraftExtensionsName,
      flag_descriptions::kWebglDraftExtensionsDescription, kOsAll,
@@ -3182,7 +3182,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableOfflinePreviewsDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(previews::features::kOfflinePreviews)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3192,7 +3192,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // OS_CHROMEOS || OS_LINUX
+#endif  // OS_CHROMEOS || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -3990,7 +3990,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
@@ -4067,7 +4067,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_WITH_PARAMS_VALUE_TYPE(omnibox::kBookmarkPaths,
                                     kOmniboxBookmarkPathsVariations,
                                     "OmniboxBundledExperimentV1")},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
     {"enable-speculative-service-worker-start-on-query-input",
@@ -4376,14 +4376,14 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
@@ -5083,7 +5083,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(kClickToCallUI)},
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"remote-copy-receiver", flag_descriptions::kRemoteCopyReceiverName,
      flag_descriptions::kRemoteCopyReceiverDescription, kOsDesktop,
@@ -5100,7 +5100,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRemoteCopyProgressNotificationName,
      flag_descriptions::kRemoteCopyProgressNotificationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyProgressNotification)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"restrict-gamepad-access", flag_descriptions::kRestrictGamepadAccessName,
@@ -5687,7 +5687,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(autofill::features::kAutofillTouchToFill)},
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
@@ -5728,7 +5728,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalMediaControlsOverlayControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsOverlayControls)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
@@ -5914,7 +5914,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          password_manager::features::kEnablePasswordsAccountStorage)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"passwords-account-storage-iph",
      flag_descriptions::kEnablePasswordsAccountStorageIPHName,
@@ -5922,7 +5922,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHPasswordsAccountStorageFeature)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"autofill-always-return-cloud-tokenized-card",
@@ -6655,7 +6655,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kEnhancedDeskAnimations)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"enable-oop-print-drivers", flag_descriptions::kEnableOopPrintDriversName,
      flag_descriptions::kEnableOopPrintDriversDescription, kOsDesktop,
@@ -6689,13 +6689,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kMuteNotificationsDuringScreenShare)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
     {"enable-ephemeral-guest-profiles-on-desktop",
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopName,
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopDescription,
      kOsWin | kOsLinux | kOsMac,
      FEATURE_VALUE_TYPE(features::kEnableEphemeralGuestProfilesOnDesktop)},
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"decouple-sync-from-android-auto-sync",
