--- chrome/browser/about_flags.cc.orig	2025-05-31 17:16:41 UTC
+++ chrome/browser/about_flags.cc
@@ -263,7 +263,7 @@
 #include "extensions/common/extension_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -353,7 +353,7 @@
 #include "device/vr/public/cpp/switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -363,7 +363,7 @@
 #include "chrome/browser/win/mica_titlebar.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_cueing/contextual_cueing_features.h"  // nogncheck
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #include "chrome/browser/enterprise/webstore/features.h"
@@ -375,7 +375,7 @@
 #include "components/user_education/common/user_education_features.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/ui_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -427,7 +427,7 @@ const FeatureEntry::Choice kPullToRefreshChoices[] = {
 #endif  // USE_AURA
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const FeatureEntry::FeatureParam kLocalNetworkAccessChecksBlock[] = {
     {"LocalNetworkAccessChecksWarn", "false"}};
@@ -543,7 +543,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -900,6 +900,26 @@ const FeatureEntry::FeatureVariation
          std::size(kWebIdentityDigitalIdentityCredentialHighRiskDialogParam),
          nullptr}};
 
+#if BUILDFLAG(IS_BSD)
+const FeatureEntry::FeatureParam kAudioBackendPulseAudio[] = {
+        { "audio-backend", "pulseaudio" }};
+const FeatureEntry::FeatureParam kAudioBackendSndio[] = {
+        { "audio-backend", "sndio" }};
+const FeatureEntry::FeatureParam kAudioBackendAlsa[] = {
+        { "audio-backend", "alsa" }};
+const FeatureEntry::FeatureVariation
+    kAudioBackendVariations[] = {
+        {"using PulseAudio by default if available", kAudioBackendPulseAudio,
+         std::size(kAudioBackendPulseAudio),
+         nullptr},
+        {"using sndio by default if available", kAudioBackendSndio,
+         std::size(kAudioBackendSndio),
+         nullptr},
+        {"using ALSA by default if available", kAudioBackendAlsa,
+         std::size(kAudioBackendAlsa),
+         nullptr}};
+#endif
+
 const FeatureEntry::FeatureParam kClipboardMaximumAge60Seconds[] = {
     {"UIClipboardMaximumAge", "60"}};
 const FeatureEntry::FeatureParam kClipboardMaximumAge90Seconds[] = {
@@ -1275,7 +1295,7 @@ constexpr FeatureEntry::FeatureVariation
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kHistoryEmbeddingsAtKeywordAcceleration[]{
     {"AtKeywordAcceleration", "true"},
 };
@@ -1313,7 +1333,7 @@ const FeatureEntry::FeatureVariation kRemotePageMetada
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -3721,7 +3741,7 @@ const FeatureEntry::FeatureVariation kAndroidThemeModu
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -4180,7 +4200,7 @@ const FeatureEntry::FeatureVariation kSkiaGraphiteVari
      std::size(kSkiaGraphite_DebugLabelsEnabled), nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kTranslationAPI_SkipLanguagePackLimit[] = {
     {"TranslationAPIAcceptLanguagesCheck", "false"},
     {"TranslationAPILimitLanguagePackCount", "false"}};
@@ -4246,7 +4266,7 @@ const FeatureEntry::FeatureVariation
          1, nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -5184,7 +5204,7 @@ const FeatureEntry kFeatureEntries[] = {
     },
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "fluent-overlay-scrollbars",
         flag_descriptions::kFluentOverlayScrollbarsName,
@@ -5476,7 +5496,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableIsolatedWebAppDevModeName,
      flag_descriptions::kEnableIsolatedWebAppDevModeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kIsolatedWebAppDevMode)},
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5698,7 +5718,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5739,6 +5759,16 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -6638,7 +6668,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"omnibox-contextual-search-actions-at-top",
      flag_descriptions::kOmniboxContextualSearchActionsAtTopName,
      flag_descriptions::kOmniboxContextualSearchActionsAtTopDescription,
@@ -6942,7 +6972,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kNumSrpZpsRelatedSearches,
                                     "PowerTools")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(history_embeddings::kHistoryEmbeddings,
@@ -7430,7 +7460,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kAddPrinterViaPrintscanmgr)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7700,7 +7730,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSupportToolScreenshotDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kSupportToolScreenshot)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"wasm-tts-component-updater-enabled",
      flag_descriptions::kWasmTtsComponentUpdaterEnabledName,
      flag_descriptions::kWasmTtsComponentUpdaterEnabledDescription, kOsDesktop,
@@ -8382,7 +8412,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsUpdatedUI)},
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -9046,7 +9076,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperGooglePhotosSharedAlbums)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kGetAllScreensMedia)},
@@ -9071,7 +9101,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9551,7 +9581,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"media-session-enter-picture-in-picture",
      flag_descriptions::kMediaSessionEnterPictureInPictureName,
      flag_descriptions::kMediaSessionEnterPictureInPictureDescription,
@@ -10223,7 +10253,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop | kOsAndroid,
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux),
@@ -10347,7 +10377,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReadAloudTapToSeek)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -10376,7 +10406,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -11094,7 +11124,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCanvasHibernationDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kCanvas2DHibernation)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-history-sync-optin",
      flag_descriptions::kEnableHistorySyncOptinName,
      flag_descriptions::kEnableHistorySyncOptinDescription,
@@ -11196,7 +11226,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kForceSupervisedSigninWithCapabilities)},
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"supervised-profile-safe-search",
      flag_descriptions::kSupervisedProfileSafeSearchName,
      flag_descriptions::kSupervisedProfileSafeSearchDescription,
@@ -11444,7 +11474,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription, kOsDesktop,
@@ -11545,7 +11575,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillEnableCardInfoRuntimeRetrieval)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"translation-api", flag_descriptions::kTranslationAPIName,
      flag_descriptions::kTranslationAPIDescription, kOsMac | kOsWin | kOsLinux,
      FEATURE_WITH_PARAMS_VALUE_TYPE(blink::features::kTranslationAPI,
@@ -11582,7 +11612,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          password_manager::features::kPasswordFormClientsideClassifier)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"contextual-cueing", flag_descriptions::kContextualCueingName,
      flag_descriptions::kContextualCueingDescription,
      kOsLinux | kOsMac | kOsWin,
@@ -11913,7 +11943,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11963,7 +11993,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-desktop",
      flag_descriptions::kAutofillEnableAmountExtractionDesktopName,
      flag_descriptions::kAutofillEnableAmountExtractionDesktopDescription,
@@ -11983,7 +12013,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(blink::features::kClipboardContentsId)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-allowlist-desktop",
      flag_descriptions::kAutofillEnableAmountExtractionAllowlistDesktopName,
      flag_descriptions::
@@ -12101,7 +12131,7 @@ const FeatureEntry kFeatureEntries[] = {
          apps::chrome_app_deprecation::kAllowUserInstalledChromeApps)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -12137,7 +12167,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-desktop-logging",
      flag_descriptions::kAutofillEnableAmountExtractionDesktopLoggingName,
      flag_descriptions::
@@ -12160,7 +12190,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableWebAppUpdateTokenParsingDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kWebAppEnableUpdateTokenParsing)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -12189,7 +12219,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"local-network-access-check",
      flag_descriptions::kLocalNetworkAccessChecksName,
      flag_descriptions::kLocalNetworkAccessChecksDescription, kOsDesktop,
