--- chrome/browser/about_flags.cc.orig	2021-12-31 00:57:21 UTC
+++ chrome/browser/about_flags.cc
@@ -204,7 +204,7 @@
 #include "ui/native_theme/native_theme_features.h"
 #include "ui/ui_features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -272,10 +272,10 @@
 #include "chrome/browser/supervised_user/supervised_user_features/supervised_user_features.h"
 #endif  // ENABLE_SUPERVISED_USERS
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
-#endif  // OS_LINUX || BUILDFLAG(IS_CHROMEOS_ASH)
+#endif  // OS_LINUX || BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "base/win/windows_version.h"
@@ -385,7 +385,7 @@ const FeatureEntry::Choice kUseAngleChoicesMac[] = {
      gl::kANGLEImplementationMetalName}};
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -985,7 +985,7 @@ const FeatureEntry::FeatureVariation kPageContentAnnot
      base::size(kPageContentAnnotationsTitleParams), nullptr},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
@@ -1193,7 +1193,7 @@ const FeatureEntry::FeatureVariation kOmniboxBookmarkP
     {"Dynamic Replace URL (Title - Path|URL)",
      kOmniboxBookmarkPathsDynamicReplaceUrl,
      base::size(kOmniboxBookmarkPathsDynamicReplaceUrl), nullptr}};
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 const FeatureEntry::FeatureVariation
@@ -3296,7 +3296,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chromeos::kLacrosTtsSupport)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3314,7 +3314,7 @@ const FeatureEntry kFeatureEntries[] = {
         kOsMac | kOsWin | kOsCrOS | kOsAndroid | kOsLinux,
         SINGLE_DISABLE_VALUE_TYPE(switches::kDisableAcceleratedVideoDecode),
     },
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     {
         "disable-accelerated-video-encode",
         flag_descriptions::kAcceleratedVideoEncodeName,
@@ -3685,7 +3685,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3695,7 +3695,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // BUILDFLAG(IS_CHROMEOS) || OS_LINUX
+#endif  // BUILDFLAG(IS_CHROMEOS) || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -3873,7 +3873,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_WIN || OS_MAC
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
@@ -4567,7 +4567,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
@@ -4676,7 +4676,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxPreserveLongerShortcutsTextName,
      flag_descriptions::kOmniboxPreserveLongerShortcutsTextDescription,
      kOsDesktop, FEATURE_VALUE_TYPE(omnibox::kPreserveLongerShortcutsText)},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -4952,12 +4952,12 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReaderModeInCCT)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"webui-feedback", flag_descriptions::kWebuiFeedbackName,
      flag_descriptions::kWebuiFeedbackDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebUIFeedback)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
@@ -5577,7 +5577,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingSendViaSyncDescription, kOsAll,
      FEATURE_VALUE_TYPE(kSharingSendViaSync)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"sharing-hub-desktop-app-menu",
      flag_descriptions::kSharingHubDesktopAppMenuName,
      flag_descriptions::kSharingHubDesktopAppMenuDescription, kOsDesktop,
@@ -5586,7 +5586,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingHubDesktopOmniboxName,
      flag_descriptions::kSharingHubDesktopOmniboxDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(sharing_hub::kSharingHubDesktopOmnibox)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
     {"ash-enable-pip-rounded-corners",
@@ -6011,14 +6011,14 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kMouseSubframeNoImplicitCaptureDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"global-media-controls-modern-ui",
      flag_descriptions::kGlobalMediaControlsModernUIName,
      flag_descriptions::kGlobalMediaControlsModernUIDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsModernUI)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"safety-tips", flag_descriptions::kSafetyTipName,
@@ -6734,7 +6734,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kIncognitoReauthenticationForAndroid)},
 #endif
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
@@ -6753,7 +6753,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kInheritNativeThemeFromParentWidgetDescription,
      kOsDesktop,
      FEATURE_VALUE_TYPE(views::features::kInheritNativeThemeFromParentWidget)},
-#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) ||
+#endif  // defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
     {"consolidated-site-storage-controls",
@@ -6867,7 +6867,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(language::kForceAppLanguagePrompt)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -7121,7 +7121,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kVp9kSVCHWDecodingDescription, kOsAll,
      FEATURE_VALUE_TYPE(media::kVp9kSVCHWDecoding)},
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {
         "ui-debug-tools",
@@ -7259,7 +7259,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chromeos::features::kLauncherAppSort)},
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-desktop-pwas-app-icon-shortcuts-menu-ui",
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIName,
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIDescription,
