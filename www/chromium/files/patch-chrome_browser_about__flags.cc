--- chrome/browser/about_flags.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/about_flags.cc
@@ -231,7 +231,7 @@
 #include "ui/ui_features.h"
 #include "url/url_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -330,7 +330,7 @@
 #include "device/vr/public/cpp/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -344,7 +344,7 @@
 #include "chrome/browser/win/titlebar_config.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -474,7 +474,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -1463,7 +1463,7 @@ const FeatureEntry::FeatureVariation kChromeRefresh202
      nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kShortcutBoostSearchAndUrl1414[] = {
     {"ShortcutBoostSearchScore", "1414"},
     {"ShortcutBoostUrlScore", "1414"}};
@@ -5295,13 +5295,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -5612,7 +5612,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(feed::kFeedSportsCard)},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"following-feed-sidepanel", flag_descriptions::kFollowingFeedSidepanelName,
      flag_descriptions::kFollowingFeedSidepanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feed::kWebUiFeed)},
@@ -6251,7 +6251,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kZeroSuggestInMemoryCaching)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-actions-ui-simplification",
      flag_descriptions::kOmniboxActionsUISimplificationName,
      flag_descriptions::kOmniboxActionsUISimplificationDescription, kOsDesktop,
@@ -7087,7 +7087,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kParallelDownloadingDescription, kOsAll,
      FEATURE_VALUE_TYPE(download::features::kParallelDownloading)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-async-dns", flag_descriptions::kAsyncDnsName,
      flag_descriptions::kAsyncDnsDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAsyncDns)},
@@ -8122,7 +8122,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(supervised_user::kEnableProtoApiForClassifyUrl)},
 #endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8147,7 +8147,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          supervised_user::kFilterWebsitesForSupervisedUsersOnDesktopAndIOS)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-family-link-extensions-permissions",
      flag_descriptions::
          kEnableExtensionsPermissionsForSupervisedUsersOnDesktopName,
@@ -8817,7 +8817,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"quick-commands", flag_descriptions::kQuickCommandsName,
      flag_descriptions::kQuickCommandsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kQuickCommands)},
@@ -9088,7 +9088,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperPerDesk)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription,
      kOsCrOS | kOsLacros | kOsLinux,
@@ -9130,7 +9130,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9688,7 +9688,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"document-picture-in-picture-api",
      flag_descriptions::kDocumentPictureInPictureApiName,
      flag_descriptions::kDocumentPictureInPictureApiDescription,
@@ -10795,7 +10795,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux | kOsFuchsia),
@@ -10977,7 +10977,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kFillingAcrossAffiliatedWebsitesAndroid)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -11291,7 +11291,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop, FEATURE_VALUE_TYPE(blink::features::kPasswordStrongLabel)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"attach-logs-to-autofill-rater-extentsion-report",
      flag_descriptions::kAttachLogsToAutofillRaterExtensionReportName,
      flag_descriptions::kAttachLogsToAutofillRaterExtensionReportDescription,
@@ -11300,7 +11300,7 @@ const FeatureEntry kFeatureEntries[] = {
                             kAttachLogsToAutofillRaterExtensionReport)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"fill-multi-line", flag_descriptions::kFillMultiLineName,
      flag_descriptions::kFillMultiLineDescription, kOsWin | kOsLinux | kOsMac,
      FEATURE_VALUE_TYPE(compose::features::kFillMultiLine)},
