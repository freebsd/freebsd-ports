--- chrome/browser/about_flags.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/about_flags.cc
@@ -347,13 +347,13 @@
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
@@ -361,7 +361,7 @@
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/new_tab_page/composebox/variations/composebox_fieldtrial.h"  // nogncheck
 #include "chrome/browser/glic/suggestions/contextual_cueing_features.h"  // nogncheck
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -371,7 +371,7 @@
 #include "components/enterprise/platform_auth/platform_auth_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/reporting/reporting_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -933,6 +933,23 @@ const FeatureEntry::FeatureVariation
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
@@ -1414,7 +1431,7 @@ const FeatureEntry::FeatureVariation
          kContextManagementKeepMenuOpenAndTabDeselectionParams, nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -1643,7 +1660,7 @@ const FeatureEntry::FeatureVariation
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 const FeatureEntry::FeatureParam kComposeboxNextThreadsRail[] = {
     {"EnableThreadsRail", "true"},
@@ -3324,7 +3341,7 @@ const FeatureEntry::FeatureVariation kAndroidThemeReso
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -3350,7 +3367,7 @@ const flags_ui::FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kReplaceSyncPromosWithSignInPromosDesktopFeatures[] =
     "ReplaceSyncPromosWithSignInPromos,"
     "IPH_SignInBenefits,"
@@ -3540,7 +3557,7 @@ const FeatureEntry::FeatureVariation kSensitiveContent
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4205,7 +4222,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kNtpCustomizeChromeAutoOpenOnEveryNTP[] = {
     {"max_customize_chrome_auto_shown_count", "5"},
     {"max_customize_chrome_auto_shown_session_count", "5"}};
@@ -4308,7 +4325,7 @@ const FeatureEntry::FeatureVariation kRefreshTokenBind
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kProjectsPanelWithoutThreadsVariation[] = {
     {"include_threads_in_projects_panel", "false"}};
 const FeatureEntry::FeatureParam kProjectsPanelWithThreadsVariation[] = {
@@ -4353,7 +4370,7 @@ const FeatureEntry::FeatureVariation kCrossDeviceSigni
 };
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kCrossDeviceSigninFromDesktopDefaultUrl[] = {
     {"url",
      "https://www.google.com/chrome/go-mobile?entry_point_id=1&email=$1"},
@@ -5508,7 +5525,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableProcessIsolationUiDescription, kOsWin,
      FEATURE_VALUE_TYPE(features::kProcessIsolationSettings)},
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5725,7 +5742,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kUseSCContentSharingPicker)},
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5740,6 +5757,16 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -6162,7 +6189,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kFillOnAccountSelectDescription, kOsAll,
      FEATURE_VALUE_TYPE(password_manager::features::kFillOnAccountSelect)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"first-run-desktop-choice-screen-refresh",
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshName,
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshDescription,
@@ -6477,7 +6504,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-search-box-uses-contextual-search-provider",
      flag_descriptions::kContextualSearchBoxUsesContextualSearchProviderName,
      flag_descriptions::
@@ -6906,7 +6933,7 @@ const FeatureEntry kFeatureEntries[] = {
          kVoiceSearchCoherenceComposeboxVariations,
          "VoiceSearchCoherenceComposeboxVariations")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(history_embeddings::kHistoryEmbeddings)},
@@ -7169,7 +7196,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kContextMenuAnimationLimiting)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"ntp-customize-chrome-auto-open",
      flag_descriptions::kNtpCustomizeChromeAutoOpenName,
      flag_descriptions::kNtpCustomizeChromeAutoOpenDescription, kOsDesktop,
@@ -7414,7 +7441,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(ENABLE_PRINTING)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7631,7 +7658,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kHeadlessCaptionEarlyStart)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-input-protection", flag_descriptions::kEnableInputProtectionName,
      flag_descriptions::kEnableInputProtectionDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(views::features::kEnableInputProtection)},
@@ -8183,7 +8210,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kGesturePropertiesDBusService)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8614,7 +8641,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9253,7 +9280,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kAnnotatorMode)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"approximate-geolocation-permission",
      flag_descriptions::kApproximateGeolocationPermissionName,
      flag_descriptions::kApproximateGeolocationPermissionDescription,
@@ -9750,7 +9777,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillEnablePrefetchingRiskDataForRetrieval)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-generic-oidc-auth-profile-management",
      flag_descriptions::kEnableGenericOidcAuthProfileManagementName,
      flag_descriptions::kEnableGenericOidcAuthProfileManagementDescription,
@@ -9760,7 +9787,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10117,7 +10144,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kResponsiveIframesDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kResponsiveIframes)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"replace-sync-promos-with-sign-in-promos-desktop",
      flag_descriptions::kReplaceSyncPromosWithSignInPromosName,
      flag_descriptions::kReplaceSyncPromosWithSignInPromosDescription,
@@ -10484,7 +10511,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription,
@@ -10965,7 +10992,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -10988,7 +11015,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction",
      flag_descriptions::kAutofillEnableAmountExtractionName,
      flag_descriptions::kAutofillEnableAmountExtractionDescription,
@@ -11110,7 +11137,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHAutofillCreditCardBenefitFeature)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11150,7 +11177,7 @@ const FeatureEntry kFeatureEntries[] = {
          supervised_user::kSupervisedUserUseUrlFilteringService)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-testing",
      flag_descriptions::kAutofillEnableAmountExtractionTestingName,
      flag_descriptions::kAutofillEnableAmountExtractionTestingDescription,
@@ -11160,7 +11187,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11336,7 +11363,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-group-home", tabs::flag_descriptions::kTabGroupHomeName,
      tabs::flag_descriptions::kTabGroupHomeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tabs::kTabGroupHome)},
@@ -11370,7 +11397,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-site-search-allow-user-override-policy",
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyName,
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyDescription,
@@ -11454,7 +11481,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-klarna",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaDescription,
@@ -11499,7 +11526,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-externally-linked",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForExternallyLinkedName,
      flag_descriptions::
@@ -11555,7 +11582,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cross-device-signin-from-desktop",
      flag_descriptions::kCrossDeviceSigninFromDesktopName,
      flag_descriptions::kCrossDeviceSigninFromDesktopDescription,
@@ -11873,7 +11900,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-suggestion-ui-improvements",
      flag_descriptions::kContextualSuggestionsUiImprovementsName,
      flag_descriptions::kContextualSuggestionsUiImprovementsDescription,
@@ -12078,7 +12105,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCryptographyComplianceCnsa)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-reinvocation-affordance",
      flag_descriptions::kLensSearchReinvocationAffordanceName,
      flag_descriptions::kLensSearchReinvocationAffordanceDescription,
@@ -12122,7 +12149,7 @@ const FeatureEntry kFeatureEntries[] = {
      STRING_VALUE_TYPE(variations::switches::kVariationsSeedCorpus, "")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"passkey-unlock-error-ui", flag_descriptions::kPasskeyUnlockErrorUiName,
      flag_descriptions::kPasskeyUnlockErrorUiDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(device::kPasskeyUnlockErrorUi)},
@@ -12162,7 +12189,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHandleMdmErrorsForDasherAccountsDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kHandleMdmErrorsForDasherAccounts)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"disable-u18-feedback-desktop",
      flag_descriptions::kDisableU18FeedbackDesktopName,
      flag_descriptions::kDisableU18FeedbackDesktopDescription,
@@ -12170,7 +12197,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kDisableU18FeedbackDesktop)},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-decline-signin-cta-experiment",
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentName,
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentDescription,
@@ -12191,7 +12218,7 @@ const FeatureEntry kFeatureEntries[] = {
          enterprise_signals::features::kProfileSignalsReportingEnabled)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"projects-panel", flag_descriptions::kProjectsPanelName,
      flag_descriptions::kProjectsPanelDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(tab_groups::kProjectsPanel,
@@ -12225,7 +12252,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-optimization-filter",
      flag_descriptions::kLensOverlayOptimizationFilterName,
      flag_descriptions::kLensOverlayOptimizationFilterDescription, kOsDesktop,
@@ -12252,7 +12279,7 @@ const FeatureEntry kFeatureEntries[] = {
      MULTI_VALUE_TYPE(kConnectionAllowlistsChoices)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-with-readability-enabled",
      flag_descriptions::kReadAnythingWithReadabilityName,
      flag_descriptions::kReadAnythingWithReadabilityDescription, kOsDesktop,
@@ -12260,7 +12287,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-omnibox-chip",
      flag_descriptions::kReadAnythingOmniboxChipName,
      flag_descriptions::kReadAnythingOmniboxChipDescription, kOsDesktop,
@@ -12289,7 +12316,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-non-blocking-privacy-notice",
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeName,
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeDescription,
@@ -12356,7 +12383,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-your-saved-info-settings-page",
      flag_descriptions::kYourSavedInfoSettingsPageName,
      flag_descriptions::kYourSavedInfoSettingsPageDescription, kOsDesktop,
@@ -12522,7 +12549,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(autofill::features::kAutofillAiWithDataSchema)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-line-focus", flag_descriptions::kReadAnythingLineFocusName,
      flag_descriptions::kReadAnythingLineFocusDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kReadAnythingLineFocus)},
@@ -12546,7 +12573,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(payments::android::kDeduplicateNativePaymentApps)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"password-upload-ui-update",
      flag_descriptions::kPasswordUploadUiUpdateName,
      flag_descriptions::kPasswordUploadUiUpdateDescription,
@@ -12595,7 +12622,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kAndroidXrImmersivePlayer)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"saas-usage-reporting", flag_descriptions::kSaasUsageReportingName,
      flag_descriptions::kSaasUsageReportingDescription,
      kOsLinux | kOsMac | kOsWin,
@@ -13002,7 +13029,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(blink::features::kUserMediaElementLegacy)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-readability-select-text",
      flag_descriptions::kReadAnythingReadabilitySelectTextName,
      flag_descriptions::kReadAnythingReadabilitySelectTextDescription,
@@ -13310,7 +13337,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kLongScreenshotsNoMemoryCheckDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(chrome::android::kLongScreenshotsNoMemoryCheck)},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"device-signals-backfill-disclaimer",
      flag_descriptions::kDeviceSignalsBackfillDisclaimerName,
      flag_descriptions::kDeviceSignalsBackfillDisclaimerDescription,
