--- chrome/browser/about_flags.cc.orig	2022-10-29 17:50:56 UTC
+++ chrome/browser/about_flags.cc
@@ -215,7 +215,7 @@
 #include "ui/native_theme/native_theme_features.h"
 #include "ui/ui_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -290,7 +290,7 @@
 #include "chrome/browser/supervised_user/supervised_user_features/supervised_user_features.h"  // nogncheck
 #endif  // ENABLE_SUPERVISED_USERS
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -395,7 +395,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -1255,7 +1255,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -4079,7 +4079,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(base::kOneGroupPerRenderer)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -4667,7 +4667,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
@@ -4686,7 +4686,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kForceInitialSyncWhenDecryptionFails)},
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -4946,7 +4946,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(feed::kDiscoFeedEndpoint)},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"following-feed-sidepanel", flag_descriptions::kFollowingFeedSidepanelName,
      flag_descriptions::kFollowingFeedSidepanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feed::kWebUiFeed)},
@@ -5487,7 +5487,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kZeroSuggestInMemoryCaching)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -6025,7 +6025,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kPointerLockOptionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kPointerLockOptions)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-async-dns", flag_descriptions::kAsyncDnsName,
      flag_descriptions::kAsyncDnsDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAsyncDns)},
@@ -6969,7 +6969,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"global-media-controls-modern-ui",
      flag_descriptions::kGlobalMediaControlsModernUIName,
      flag_descriptions::kGlobalMediaControlsModernUIDescription,
@@ -7839,7 +7839,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"quick-commands", flag_descriptions::kQuickCommandsName,
      flag_descriptions::kQuickCommandsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kQuickCommands)},
@@ -8154,7 +8154,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -8763,7 +8763,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"document-picture-in-picture-api",
      flag_descriptions::kDocumentPictureInPictureApiName,
      flag_descriptions::kDocumentPictureInPictureApiDescription,
