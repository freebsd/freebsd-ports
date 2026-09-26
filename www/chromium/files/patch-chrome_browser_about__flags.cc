--- chrome/browser/about_flags.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/about_flags.cc
@@ -359,13 +359,13 @@
 #include "components/stylus_handwriting/win/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/allocator/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/data_protection/data_protection_features.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #include "chrome/browser/enterprise/webstore/features.h"
@@ -373,7 +373,7 @@
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/glic/suggestions/contextual_cueing_features.h"  // nogncheck
 #include "chrome/browser/ui/webui/new_tab_page/composebox/variations/composebox_fieldtrial.h"  // nogncheck
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -383,7 +383,7 @@
 #include "components/enterprise/platform_auth/platform_auth_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/reporting/reporting_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -973,6 +973,23 @@ const FeatureEntry::FeatureVariation
          "identity request to Android OS",
          kWebIdentityDigitalIdentityCredentialHighRiskDialogParam, nullptr}};
 
+#if BUILDFLAG(IS_BSD)
+const FeatureEntry::FeatureParam kAudioBackendPulseAudio[] = {
+        { "audio-backend", "pulseaudio" }};
+const FeatureEntry::FeatureParam kAudioBackendSndio[] = {
+        { "audio-backend", "sndio" }};
+const FeatureEntry::FeatureParam kAudioBackendAlsa[] = {
+        { "audio-backend", "alsa" }};
+const FeatureEntry::FeatureVariation
+    kAudioBackendVariations[] = {
+        {"using PulseAudio by default if available",
+         kAudioBackendPulseAudio, nullptr},
+        {"using sndio by default if available",
+         kAudioBackendSndio, nullptr},
+        {"using ALSA by default if available",
+         kAudioBackendAlsa, nullptr}};
+#endif
+
 const FeatureEntry::FeatureParam kMBIModeLegacy[] = {{"mode", "legacy"}};
 const FeatureEntry::FeatureParam kMBIModeEnabledPerRenderProcessHost[] = {
     {"mode", "per_render_process_host"}};
@@ -1452,7 +1469,7 @@ const FeatureEntry::FeatureVariation
          kContextManagementEnableContextMenuTooltipsParams, nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -1681,7 +1698,7 @@ const FeatureEntry::FeatureVariation
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 const FeatureEntry::FeatureParam kNtpNextAllowDisablement[] = {
     {"NtpNextDisablementContextMenuParam", "true"},
@@ -3369,7 +3386,7 @@ const FeatureEntry::FeatureVariation kAndroidThemeReso
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -3401,7 +3418,7 @@ const flags_ui::FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kReplaceSyncPromosWithSignInPromosDesktopFeatures[] =
     "ReplaceSyncPromosWithSignInPromos,"
     "IPH_SignInBenefits,"
@@ -3499,7 +3516,7 @@ const FeatureEntry::FeatureVariation kComposeSelection
     {"30 char - 2sec", kComposeSelectionNudge_30_2s, nullptr}};
 #endif  // ENABLE_COMPOSE
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kLocationProviderManagerModeNetworkOnly[] = {
     {"LocationProviderManagerMode", "NetworkOnly"}};
 const FeatureEntry::FeatureParam kLocationProviderManagerModePlatformOnly[] = {
@@ -3589,7 +3606,7 @@ const FeatureEntry::FeatureVariation kSensitiveContent
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4269,7 +4286,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kNtpCustomizeChromeAutoOpenOnEveryNTP[] = {
     {"max_customize_chrome_auto_shown_count", "5"},
     {"max_customize_chrome_auto_shown_session_count", "5"}};
@@ -4417,7 +4434,7 @@ const FeatureEntry::FeatureVariation kXplatSyncedSetup
 };
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kCrossDeviceSigninFromDesktopDefaultUrl[] = {
     {"url",
      "https://www.google.com/chrome/go-mobile?entry_point_id=1&email=$1"},
@@ -5766,7 +5783,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableProcessIsolationUiDescription, kOsWin,
      FEATURE_VALUE_TYPE(features::kProcessIsolationSettings)},
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5976,7 +5993,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kUseSCContentSharingPicker)},
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5991,6 +6008,16 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWaylandSessionManagementName,
      flag_descriptions::kWaylandSessionManagementDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kWaylandSessionManagement)},
+
+#if BUILDFLAG(IS_BSD)
+    {"audio-backend",
+     flag_descriptions::kAudioBackendName,
+     flag_descriptions::kAudioBackendDescription, kOsLinux,
+     FEATURE_WITH_PARAMS_VALUE_TYPE(
+         media::kAudioBackend,
+         kAudioBackendVariations,
+         "AudioBackend")},
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(ENABLE_VR)
@@ -6421,7 +6448,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kFillOnAccountSelectDescription, kOsAll,
      FEATURE_VALUE_TYPE(password_manager::features::kFillOnAccountSelect)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"first-run-desktop-choice-screen-refresh",
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshName,
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshDescription,
@@ -6727,7 +6754,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-search-box-uses-contextual-search-provider",
      flag_descriptions::kContextualSearchBoxUsesContextualSearchProviderName,
      flag_descriptions::
@@ -7131,7 +7158,7 @@ const FeatureEntry kFeatureEntries[] = {
          kVoiceSearchCoherenceComposeboxVariations,
          "VoiceSearchCoherenceComposeboxVariations")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(history_embeddings::kHistoryEmbeddings)},
@@ -7419,7 +7446,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kContextMenuAnimationLimiting)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"ntp-customize-chrome-auto-open",
      flag_descriptions::kNtpCustomizeChromeAutoOpenName,
      flag_descriptions::kNtpCustomizeChromeAutoOpenDescription, kOsDesktop,
@@ -7689,7 +7716,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(ENABLE_PRINTING)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7911,7 +7938,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kHeadlessCaptionEarlyStart)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-input-protection", flag_descriptions::kEnableInputProtectionName,
      flag_descriptions::kEnableInputProtectionDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(views::features::kEnableInputProtection)},
@@ -8427,7 +8454,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kGesturePropertiesDBusService)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8511,7 +8538,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kViewportSegmentsDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kViewportSegments)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-location-provider-manager",
      flag_descriptions::kLocationProviderManagerName,
      flag_descriptions::kLocationProviderManagerDescription,
@@ -8860,7 +8887,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9333,7 +9360,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"auto-picture-in-picture-on-window-occluded",
      flag_descriptions::kAutoPictureInPictureOnWindowOccludedName,
      flag_descriptions::kAutoPictureInPictureOnWindowOccludedDescription,
@@ -9522,7 +9549,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kAnnotatorMode)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"approximate-geolocation-permission",
      flag_descriptions::kApproximateGeolocationPermissionName,
      flag_descriptions::kApproximateGeolocationPermissionDescription,
@@ -10063,7 +10090,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillEnablePrefetchingRiskDataForRetrieval)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10486,7 +10513,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kResponsiveIframesDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kResponsiveIframes)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"replace-sync-promos-with-sign-in-promos-desktop",
      flag_descriptions::kReplaceSyncPromosWithSignInPromosName,
      flag_descriptions::kReplaceSyncPromosWithSignInPromosDescription,
@@ -10845,7 +10872,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription,
@@ -11451,7 +11478,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11474,7 +11501,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction",
      flag_descriptions::kAutofillEnableAmountExtractionName,
      flag_descriptions::kAutofillEnableAmountExtractionDescription,
@@ -11585,7 +11612,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHAutofillCreditCardBenefitFeature)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11601,7 +11628,7 @@ const FeatureEntry kFeatureEntries[] = {
          printing::features::kAlignPdfDefaultPrintSettingsWithHTML)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-testing",
      flag_descriptions::kAutofillEnableAmountExtractionTestingName,
      flag_descriptions::kAutofillEnableAmountExtractionTestingDescription,
@@ -11611,7 +11638,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11776,7 +11803,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-group-home", tabs::flag_descriptions::kTabGroupHomeName,
      tabs::flag_descriptions::kTabGroupHomeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tabs::kTabGroupHome)},
@@ -11883,7 +11910,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-klarna",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaDescription,
@@ -11927,7 +11954,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-externally-linked",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForExternallyLinkedName,
      flag_descriptions::
@@ -12003,7 +12030,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cross-device-signin-from-desktop",
      flag_descriptions::kCrossDeviceSigninFromDesktopName,
      flag_descriptions::kCrossDeviceSigninFromDesktopDescription,
@@ -12308,7 +12335,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-suggestion-ui-improvements",
      flag_descriptions::kContextualSuggestionsUiImprovementsName,
      flag_descriptions::kContextualSuggestionsUiImprovementsDescription,
@@ -12524,7 +12551,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCryptographyComplianceCnsa)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-reinvocation-affordance",
      flag_descriptions::kLensSearchReinvocationAffordanceName,
      flag_descriptions::kLensSearchReinvocationAffordanceDescription,
@@ -12560,7 +12587,7 @@ const FeatureEntry kFeatureEntries[] = {
      STRING_VALUE_TYPE(variations::switches::kVariationsSeedCorpus, "")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"passkey-unlock-error-ui", flag_descriptions::kPasskeyUnlockErrorUiName,
      flag_descriptions::kPasskeyUnlockErrorUiDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(device::kPasskeyUnlockErrorUi)},
@@ -12595,7 +12622,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHandleMdmErrorsForDasherAccountsDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kHandleMdmErrorsForDasherAccounts)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-decline-signin-cta-experiment",
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentName,
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentDescription,
@@ -12616,7 +12643,7 @@ const FeatureEntry kFeatureEntries[] = {
          enterprise_signals::features::kProfileSignalsReportingEnabled)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"organizer-panel", flag_descriptions::kOrganizerPanelName,
      flag_descriptions::kOrganizerPanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(organizer_panel::kOrganizerPanel)},
@@ -12667,7 +12694,7 @@ const FeatureEntry kFeatureEntries[] = {
      MULTI_VALUE_TYPE(kConnectionAllowlistsChoices)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-with-readability-enabled",
      flag_descriptions::kReadAnythingWithReadabilityName,
      flag_descriptions::kReadAnythingWithReadabilityDescription, kOsDesktop,
@@ -12675,7 +12702,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-omnibox-chip",
      flag_descriptions::kReadAnythingOmniboxChipName,
      flag_descriptions::kReadAnythingOmniboxChipDescription, kOsDesktop,
@@ -12697,7 +12724,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillDisableBnplCountryCheckForTesting)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-non-blocking-privacy-notice",
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeName,
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeDescription,
@@ -12914,7 +12941,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(autofill::features::kAutofillAiWithDataSchema)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-line-focus", flag_descriptions::kReadAnythingLineFocusName,
      flag_descriptions::kReadAnythingLineFocusDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kReadAnythingLineFocus)},
@@ -13404,7 +13431,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(blink::features::kUserMediaElementLegacy)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-readability-select-text",
      flag_descriptions::kReadAnythingReadabilitySelectTextName,
      flag_descriptions::kReadAnythingReadabilitySelectTextDescription,
@@ -13741,7 +13768,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kLongScreenshotsNoMemoryCheckDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(chrome::android::kLongScreenshotsNoMemoryCheck)},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"device-signals-backfill-disclaimer",
      flag_descriptions::kDeviceSignalsBackfillDisclaimerName,
      flag_descriptions::kDeviceSignalsBackfillDisclaimerDescription,
@@ -13831,7 +13858,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-improved-ui",
      flag_descriptions::kReadAnythingImprovedUiName,
      flag_descriptions::kReadAnythingImprovedUiDescription, kOsDesktop,
@@ -13931,7 +13958,7 @@ const FeatureEntry kFeatureEntries[] = {
              kAutofillIgnorePaymentsChurnedUsersStrikesForTesting)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-distiller-refactor",
      flag_descriptions::kReadAnythingDistillerRefactorName,
      flag_descriptions::kReadAnythingDistillerRefactorDescription, kOsDesktop,
