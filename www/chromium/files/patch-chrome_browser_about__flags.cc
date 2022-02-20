--- chrome/browser/about_flags.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/about_flags.cc
@@ -203,7 +203,7 @@
 #include "ui/native_theme/native_theme_features.h"
 #include "ui/ui_features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -271,7 +271,7 @@
 #include "chrome/browser/supervised_user/supervised_user_features/supervised_user_features.h"
 #endif  // ENABLE_SUPERVISED_USERS
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // OS_LINUX || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -358,7 +358,7 @@ const FeatureEntry::Choice kUseAngleChoicesMac[] = {
      gl::kANGLEImplementationMetalName}};
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -941,7 +941,7 @@ const FeatureEntry::FeatureVariation kPageContentAnnot
 };
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_FUCHSIA)
+    defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -2344,7 +2344,7 @@ const FeatureEntry::FeatureVariation kPasswordChangeFe
      nullptr}};
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const FeatureEntry::FeatureParam
     kSendWebUIJavaScriptErrorReportsVariationSendToStaging[] = {
         {features::kSendWebUIJavaScriptErrorReportsSendToProductionVariation,
@@ -2699,7 +2699,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWebKioskEnableLacrosDescription, kOsCrOS,
      FEATURE_VALUE_TYPE(features::kWebKioskEnableLacros)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"send-webui-javascript-error-reports",
      flag_descriptions::kSendWebUIJavaScriptErrorReportsName,
      flag_descriptions::kSendWebUIJavaScriptErrorReportsDescription,
@@ -3208,7 +3208,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chromeos::kLacrosTtsSupport)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3620,7 +3620,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3808,7 +3808,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_WIN || OS_MAC
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
@@ -4493,7 +4493,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OmniboxBundledExperimentV1")},
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_FUCHSIA)
+    defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -4870,7 +4870,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
     {"webui-feedback", flag_descriptions::kWebuiFeedbackName,
      flag_descriptions::kWebuiFeedbackDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebUIFeedback)},
@@ -5492,7 +5492,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(kSharingSendViaSync)},
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
     {"sharing-hub-desktop-app-menu",
      flag_descriptions::kSharingHubDesktopAppMenuName,
      flag_descriptions::kSharingHubDesktopAppMenuDescription, kOsDesktop,
@@ -5917,7 +5917,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
     {"global-media-controls-modern-ui",
      flag_descriptions::kGlobalMediaControlsModernUIName,
      flag_descriptions::kGlobalMediaControlsModernUIDescription,
@@ -6606,7 +6606,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
      flag_descriptions::kIncognitoBrandConsistencyForDesktopDescription,
@@ -6739,7 +6739,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -6982,7 +6982,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kVp9kSVCHWDecoding)},
 
 #if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -7124,7 +7124,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
     {"enable-desktop-pwas-app-icon-shortcuts-menu-ui",
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIName,
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIDescription,
