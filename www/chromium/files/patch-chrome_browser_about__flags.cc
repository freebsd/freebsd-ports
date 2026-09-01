--- chrome/browser/about_flags.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/about_flags.cc
@@ -353,13 +353,13 @@
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
@@ -367,7 +367,7 @@
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/new_tab_page/composebox/variations/composebox_fieldtrial.h"  // nogncheck
 #include "chrome/browser/glic/suggestions/contextual_cueing_features.h"  // nogncheck
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -377,7 +377,7 @@
 #include "components/enterprise/platform_auth/platform_auth_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/reporting/reporting_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -931,6 +931,23 @@ const FeatureEntry::FeatureVariation
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
@@ -1494,7 +1511,7 @@ const FeatureEntry::FeatureVariation
          kContextManagementKeepMenuOpenAndTabDeselectionParams, nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -1723,7 +1740,7 @@ const FeatureEntry::FeatureVariation
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 const FeatureEntry::FeatureParam kNtpNextAllowDisablement[] = {
     {"NtpNextDisablementContextMenuParam", "true"},
@@ -3379,7 +3396,7 @@ const FeatureEntry::FeatureVariation kAndroidThemeReso
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -3411,7 +3428,7 @@ const flags_ui::FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kReplaceSyncPromosWithSignInPromosDesktopFeatures[] =
     "ReplaceSyncPromosWithSignInPromos,"
     "IPH_SignInBenefits,"
@@ -3601,7 +3618,7 @@ const FeatureEntry::FeatureVariation kSensitiveContent
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4256,7 +4273,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kNtpCustomizeChromeAutoOpenOnEveryNTP[] = {
     {"max_customize_chrome_auto_shown_count", "5"},
     {"max_customize_chrome_auto_shown_session_count", "5"}};
@@ -4388,7 +4405,7 @@ const FeatureEntry::FeatureVariation kCrossDeviceSigni
 };
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kCrossDeviceSigninFromDesktopDefaultUrl[] = {
     {"url",
      "https://www.google.com/chrome/go-mobile?entry_point_id=1&email=$1"},
@@ -5641,7 +5658,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableProcessIsolationUiDescription, kOsWin,
      FEATURE_VALUE_TYPE(features::kProcessIsolationSettings)},
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5855,7 +5872,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kUseSCContentSharingPicker)},
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5870,6 +5887,16 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -6289,7 +6316,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kFillOnAccountSelectDescription, kOsAll,
      FEATURE_VALUE_TYPE(password_manager::features::kFillOnAccountSelect)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"first-run-desktop-choice-screen-refresh",
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshName,
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshDescription,
@@ -6607,7 +6634,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-search-box-uses-contextual-search-provider",
      flag_descriptions::kContextualSearchBoxUsesContextualSearchProviderName,
      flag_descriptions::
@@ -7049,7 +7076,7 @@ const FeatureEntry kFeatureEntries[] = {
          kVoiceSearchCoherenceComposeboxVariations,
          "VoiceSearchCoherenceComposeboxVariations")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(history_embeddings::kHistoryEmbeddings)},
@@ -7330,7 +7357,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kContextMenuAnimationLimiting)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"ntp-customize-chrome-auto-open",
      flag_descriptions::kNtpCustomizeChromeAutoOpenName,
      flag_descriptions::kNtpCustomizeChromeAutoOpenDescription, kOsDesktop,
@@ -7599,7 +7626,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(ENABLE_PRINTING)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7823,7 +7850,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kHeadlessCaptionEarlyStart)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-input-protection", flag_descriptions::kEnableInputProtectionName,
      flag_descriptions::kEnableInputProtectionDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(views::features::kEnableInputProtection)},
@@ -8356,7 +8383,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kGesturePropertiesDBusService)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8784,7 +8811,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9244,7 +9271,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"auto-picture-in-picture-on-window-occluded",
      flag_descriptions::kAutoPictureInPictureOnWindowOccludedName,
      flag_descriptions::kAutoPictureInPictureOnWindowOccludedDescription,
@@ -9428,7 +9455,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kAnnotatorMode)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"approximate-geolocation-permission",
      flag_descriptions::kApproximateGeolocationPermissionName,
      flag_descriptions::kApproximateGeolocationPermissionDescription,
@@ -9965,7 +9992,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillEnablePrefetchingRiskDataForRetrieval)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-generic-oidc-auth-profile-management",
      flag_descriptions::kEnableGenericOidcAuthProfileManagementName,
      flag_descriptions::kEnableGenericOidcAuthProfileManagementDescription,
@@ -9975,7 +10002,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10360,7 +10387,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kResponsiveIframesDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kResponsiveIframes)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"replace-sync-promos-with-sign-in-promos-desktop",
      flag_descriptions::kReplaceSyncPromosWithSignInPromosName,
      flag_descriptions::kReplaceSyncPromosWithSignInPromosDescription,
@@ -10722,7 +10749,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription,
@@ -11241,7 +11268,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11264,7 +11291,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction",
      flag_descriptions::kAutofillEnableAmountExtractionName,
      flag_descriptions::kAutofillEnableAmountExtractionDescription,
@@ -11392,7 +11419,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHAutofillCreditCardBenefitFeature)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11432,7 +11459,7 @@ const FeatureEntry kFeatureEntries[] = {
          supervised_user::kSupervisedUserUseUrlFilteringService)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-testing",
      flag_descriptions::kAutofillEnableAmountExtractionTestingName,
      flag_descriptions::kAutofillEnableAmountExtractionTestingDescription,
@@ -11442,7 +11469,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11613,7 +11640,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-group-home", tabs::flag_descriptions::kTabGroupHomeName,
      tabs::flag_descriptions::kTabGroupHomeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tabs::kTabGroupHome)},
@@ -11647,7 +11674,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-site-search-allow-user-override-policy",
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyName,
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyDescription,
@@ -11731,7 +11758,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-klarna",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaDescription,
@@ -11776,7 +11803,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-externally-linked",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForExternallyLinkedName,
      flag_descriptions::
@@ -11837,7 +11864,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cross-device-signin-from-desktop",
      flag_descriptions::kCrossDeviceSigninFromDesktopName,
      flag_descriptions::kCrossDeviceSigninFromDesktopDescription,
@@ -12146,7 +12173,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-suggestion-ui-improvements",
      flag_descriptions::kContextualSuggestionsUiImprovementsName,
      flag_descriptions::kContextualSuggestionsUiImprovementsDescription,
@@ -12368,7 +12395,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCryptographyComplianceCnsa)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-reinvocation-affordance",
      flag_descriptions::kLensSearchReinvocationAffordanceName,
      flag_descriptions::kLensSearchReinvocationAffordanceDescription,
@@ -12412,7 +12439,7 @@ const FeatureEntry kFeatureEntries[] = {
      STRING_VALUE_TYPE(variations::switches::kVariationsSeedCorpus, "")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"passkey-unlock-error-ui", flag_descriptions::kPasskeyUnlockErrorUiName,
      flag_descriptions::kPasskeyUnlockErrorUiDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(device::kPasskeyUnlockErrorUi)},
@@ -12452,7 +12479,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHandleMdmErrorsForDasherAccountsDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kHandleMdmErrorsForDasherAccounts)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"disable-u18-feedback-desktop",
      flag_descriptions::kDisableU18FeedbackDesktopName,
      flag_descriptions::kDisableU18FeedbackDesktopDescription,
@@ -12460,7 +12487,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kDisableU18FeedbackDesktop)},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-decline-signin-cta-experiment",
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentName,
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentDescription,
@@ -12481,7 +12508,7 @@ const FeatureEntry kFeatureEntries[] = {
          enterprise_signals::features::kProfileSignalsReportingEnabled)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"organizer-panel", flag_descriptions::kOrganizerPanelName,
      flag_descriptions::kOrganizerPanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tab_groups::kOrganizerPanel)},
@@ -12532,7 +12559,7 @@ const FeatureEntry kFeatureEntries[] = {
      MULTI_VALUE_TYPE(kConnectionAllowlistsChoices)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-with-readability-enabled",
      flag_descriptions::kReadAnythingWithReadabilityName,
      flag_descriptions::kReadAnythingWithReadabilityDescription, kOsDesktop,
@@ -12540,7 +12567,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-omnibox-chip",
      flag_descriptions::kReadAnythingOmniboxChipName,
      flag_descriptions::kReadAnythingOmniboxChipDescription, kOsDesktop,
@@ -12569,7 +12596,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-non-blocking-privacy-notice",
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeName,
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeDescription,
@@ -12636,7 +12663,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-your-saved-info-settings-page",
      flag_descriptions::kYourSavedInfoSettingsPageName,
      flag_descriptions::kYourSavedInfoSettingsPageDescription, kOsDesktop,
@@ -12796,7 +12823,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(autofill::features::kAutofillAiWithDataSchema)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-line-focus", flag_descriptions::kReadAnythingLineFocusName,
      flag_descriptions::kReadAnythingLineFocusDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kReadAnythingLineFocus)},
@@ -12862,7 +12889,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"saas-usage-reporting", flag_descriptions::kSaasUsageReportingName,
      flag_descriptions::kSaasUsageReportingDescription,
      kOsLinux | kOsMac | kOsWin | kOsCrOS,
@@ -13283,7 +13310,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(blink::features::kUserMediaElementLegacy)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-readability-select-text",
      flag_descriptions::kReadAnythingReadabilitySelectTextName,
      flag_descriptions::kReadAnythingReadabilitySelectTextDescription,
@@ -13593,7 +13620,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kLongScreenshotsNoMemoryCheckDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(chrome::android::kLongScreenshotsNoMemoryCheck)},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"device-signals-backfill-disclaimer",
      flag_descriptions::kDeviceSignalsBackfillDisclaimerName,
      flag_descriptions::kDeviceSignalsBackfillDisclaimerDescription,
@@ -13678,7 +13705,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-improved-ui",
      flag_descriptions::kReadAnythingImprovedUiName,
      flag_descriptions::kReadAnythingImprovedUiDescription, kOsDesktop,
