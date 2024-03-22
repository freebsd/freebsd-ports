--- chrome/browser/about_flags.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/about_flags.cc
@@ -234,7 +234,7 @@
 #include "ui/ui_features.h"
 #include "url/url_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -326,7 +326,7 @@
 #include "device/vr/public/cpp/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
@@ -335,7 +335,7 @@
 #include "chrome/browser/win/titlebar_config.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -492,7 +492,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -1374,7 +1374,7 @@ const FeatureEntry::FeatureVariation kChromeRefresh202
      nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kShortcutBoostSingleUrl[] = {
     {"ShortcutBoostSearchScore", "0"},
     {"ShortcutBoostNonTopHitThreshold", "0"},
@@ -3687,7 +3687,7 @@ const flags_ui::FeatureEntry::FeatureVariation
          std::size(kParcelTrackingTestDataOutForDelivery), nullptr},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam
     kDesktopPWAsLinkCapturingDefaultOn[] = {{"on_by_default", "true"}};
 const flags_ui::FeatureEntry::FeatureParam
@@ -4425,7 +4425,7 @@ const FeatureEntry kFeatureEntries[] = {
     },
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "fluent-overlay-scrollbars",
         flag_descriptions::kFluentOverlayScrollbarsName,
@@ -4864,7 +4864,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebAppUniversalInstall)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"shortcuts-not-apps", flag_descriptions::kShortcutsNotAppsName,
      flag_descriptions::kShortcutsNotAppsDescription,
      kOsMac | kOsWin | kOsLinux | kOsFuchsia,
@@ -4993,7 +4993,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5009,7 +5009,7 @@ const FeatureEntry kFeatureEntries[] = {
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -5292,7 +5292,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(feed::kRefreshFeedOnRestart)},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"following-feed-sidepanel", flag_descriptions::kFollowingFeedSidepanelName,
      flag_descriptions::kFollowingFeedSidepanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feed::kWebUiFeed)},
@@ -5943,7 +5943,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kZeroSuggestInMemoryCaching)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-actions-ui-simplification",
      flag_descriptions::kOmniboxActionsUISimplificationName,
      flag_descriptions::kOmniboxActionsUISimplificationDescription, kOsDesktop,
@@ -6800,7 +6800,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kParallelDownloadingDescription, kOsAll,
      FEATURE_VALUE_TYPE(download::features::kParallelDownloading)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-async-dns", flag_descriptions::kAsyncDnsName,
      flag_descriptions::kAsyncDnsDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(net::features::kAsyncDns)},
@@ -7778,7 +7778,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kPrivacyIndicators)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -7811,7 +7811,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          supervised_user::kFilterWebsitesForSupervisedUsersOnDesktopAndIOS)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-family-link-extensions-permissions",
      flag_descriptions::
          kEnableExtensionsPermissionsForSupervisedUsersOnDesktopName,
@@ -8709,7 +8709,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperPerDesk)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription,
      kOsCrOS | kOsLacros | kOsLinux,
@@ -8751,7 +8751,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9040,7 +9040,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"policy-indication-for-managed-default-search",
      flag_descriptions::kPolicyIndicationForManagedDefaultSearchName,
      flag_descriptions::kPolicyIndicationForManagedDefaultSearchDescription,
@@ -9344,7 +9344,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"media-session-enter-picture-in-picture",
      flag_descriptions::kMediaSessionEnterPictureInPictureName,
      flag_descriptions::kMediaSessionEnterPictureInPictureDescription,
@@ -10334,7 +10334,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop | kOsAndroid,
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux),
@@ -10365,7 +10365,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kSiteInstanceGroupsForDataUrls)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"site-search-settings-policy",
      flag_descriptions::kSiteSearchSettingsPolicyName,
      flag_descriptions::kSiteSearchSettingsPolicyDescription, kOsAll,
@@ -10495,7 +10495,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kFillingAcrossAffiliatedWebsitesAndroid)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -10838,7 +10838,7 @@ const FeatureEntry kFeatureEntries[] = {
          trusted_vault::kTrustedVaultFrequentDegradedRecoverabilityPolling)},
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"restart-to-gain-access-to-keychain",
      flag_descriptions::kRestartToGainAccessToKeychainName,
      flag_descriptions::kRestartToGainAccessToKeychainDescription,
@@ -11092,7 +11092,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 // Controls the view mode for (history) sync screen.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"minor-mode-restrictions-for-history-sync-opt-in",
      flag_descriptions::kMinorModeRestrictionsForHistorySyncOptInName,
      flag_descriptions::kMinorModeRestrictionsForHistorySyncOptInDescription,
