--- chrome/browser/about_flags.cc.orig	2024-08-26 14:40:28 UTC
+++ chrome/browser/about_flags.cc
@@ -239,7 +239,7 @@
 #include "ui/ui_features.h"
 #include "url/url_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -333,7 +333,7 @@
 #include "device/vr/public/cpp/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
@@ -342,7 +342,7 @@
 #include "chrome/browser/win/mica_titlebar.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -352,7 +352,7 @@
 #include "components/user_education/common/user_education_features.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/ui_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -494,7 +494,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -894,6 +894,26 @@ const FeatureEntry::FeatureVariation
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
@@ -1307,7 +1327,7 @@ const FeatureEntry::FeatureVariation kPageContentAnnot
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kHistoryEmbeddingsAtKeywordAcceleration[]{
     {"AtKeywordAcceleration", "true"},
 };
@@ -1351,7 +1371,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kShortcutBoostSingleUrl[] = {
     {"ShortcutBoostSearchScore", "0"},
     {"ShortcutBoostNonTopHitThreshold", "0"},
@@ -3780,7 +3800,7 @@ const flags_ui::FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam
     kDesktopPWAsLinkCapturingDefaultOn[] = {
         {"link_capturing_state", "on_by_default"}};
@@ -4867,7 +4887,7 @@ const FeatureEntry kFeatureEntries[] = {
     },
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "fluent-overlay-scrollbars",
         flag_descriptions::kFluentOverlayScrollbarsName,
@@ -5286,7 +5306,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWebAppUniversalInstallDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebAppUniversalInstall)},
 #endif  // !BUILDFLAG(IS_ANDROID)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"shortcuts-not-apps", flag_descriptions::kShortcutsNotAppsName,
      flag_descriptions::kShortcutsNotAppsDescription,
      kOsMac | kOsWin | kOsLinux,
@@ -5422,7 +5442,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5445,9 +5465,19 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWaylandPerWindowScalingName,
      flag_descriptions::kWaylandPerWindowScalingDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kWaylandPerSurfaceScale)},
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
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -6442,7 +6472,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"omnibox-domain-suggestions",
      flag_descriptions::kOmniboxDomainSuggestionsName,
      flag_descriptions::kOmniboxDomainSuggestionsDescription, kOsDesktop,
@@ -6737,7 +6767,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OrganicRepeatableQueries")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(history_embeddings::kHistoryEmbeddings,
@@ -7406,7 +7436,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kAddPrinterViaPrintscanmgr)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -8426,7 +8456,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCooperativeSchedulingDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kCooperativeScheduling)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8450,7 +8480,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kV4L2FlatStatefulVideoDecoder)},
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-family-link-extensions-permissions",
      flag_descriptions::
          kEnableExtensionsPermissionsForSupervisedUsersOnDesktopName,
@@ -9301,7 +9331,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperPerDesk)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription,
      kOsCrOS | kOsLacros | kOsLinux,
@@ -9340,7 +9370,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9565,7 +9595,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"policy-indication-for-managed-default-search",
      flag_descriptions::kPolicyIndicationForManagedDefaultSearchName,
      flag_descriptions::kPolicyIndicationForManagedDefaultSearchDescription,
@@ -9905,7 +9935,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"media-session-enter-picture-in-picture",
      flag_descriptions::kMediaSessionEnterPictureInPictureName,
      flag_descriptions::kMediaSessionEnterPictureInPictureDescription,
@@ -10805,7 +10835,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop | kOsAndroid,
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux),
@@ -10843,7 +10873,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kSiteInstanceGroupsForDataUrls)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"site-search-settings-policy",
      flag_descriptions::kSiteSearchSettingsPolicyName,
      flag_descriptions::kSiteSearchSettingsPolicyDescription, kOsAll,
@@ -10968,7 +10998,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHideIncognitoMediaMetadataDescription, kOsAll,
      FEATURE_VALUE_TYPE(media::kHideIncognitoMediaMetadata)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -11011,7 +11041,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-link-capturing-pwa",
      flag_descriptions::kDesktopPWAsUserLinkCapturingName,
      flag_descriptions::kDesktopPWAsUserLinkCapturingDescription,
@@ -11327,7 +11357,7 @@ const FeatureEntry kFeatureEntries[] = {
          trusted_vault::kTrustedVaultFrequentDegradedRecoverabilityPolling)},
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"restart-to-gain-access-to-keychain",
      flag_descriptions::kRestartToGainAccessToKeychainName,
      flag_descriptions::kRestartToGainAccessToKeychainDescription,
@@ -11990,7 +12020,7 @@ const FeatureEntry kFeatureEntries[] = {
                             kAuthenticateUsingUserConsentVerifierInteropApi)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"sync-enable-bookmarks-in-transport-mode",
      flag_descriptions::kSyncEnableBookmarksInTransportModeName,
      flag_descriptions::kSyncEnableBookmarksInTransportModeDescription,
@@ -12016,7 +12046,7 @@ const FeatureEntry kFeatureEntries[] = {
          "AutofillUploadCardRequestTimeout")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-desktop",
      flag_descriptions::kAutofillEnableAmountExtractionDesktopName,
      flag_descriptions::kAutofillEnableAmountExtractionDesktopDescription,
