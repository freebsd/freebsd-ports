--- chrome/browser/about_flags.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/about_flags.cc
@@ -205,7 +205,7 @@
 #include "ui/native_theme/native_theme_features.h"
 #include "ui/ui_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -273,7 +273,7 @@
 #include "chrome/browser/supervised_user/supervised_user_features/supervised_user_features.h"
 #endif  // ENABLE_SUPERVISED_USERS
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -360,7 +360,7 @@ const FeatureEntry::Choice kUseAngleChoicesMac[] = {
      gl::kANGLEImplementationMetalName}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -966,7 +966,7 @@ const FeatureEntry::FeatureVariation kPageContentAnnot
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -3243,7 +3243,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chromeos::kLacrosTtsSupport)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3648,7 +3648,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3835,7 +3835,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
@@ -4518,7 +4518,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OmniboxBundledExperimentV1")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -4887,7 +4887,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"webui-feedback", flag_descriptions::kWebuiFeedbackName,
      flag_descriptions::kWebuiFeedbackDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kWebUIFeedback)},
@@ -5897,7 +5897,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"global-media-controls-modern-ui",
      flag_descriptions::kGlobalMediaControlsModernUIName,
      flag_descriptions::kGlobalMediaControlsModernUIDescription,
@@ -6607,7 +6607,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
      flag_descriptions::kIncognitoBrandConsistencyForDesktopDescription,
@@ -6740,7 +6740,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -6985,7 +6985,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -7129,7 +7129,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"enable-desktop-pwas-app-icon-shortcuts-menu-ui",
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIName,
      flag_descriptions::kDesktopPWAsAppIconShortcutsMenuUIDescription,
@@ -7685,7 +7685,7 @@ const FeatureEntry kFeatureEntries[] = {
      SINGLE_VALUE_TYPE(switches::kPervasiveSystemAccentColor)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"improve-accessibility-tree-using-local-ml",
      flag_descriptions::kImproveAccessibilityTreeUsingLocalMLName,
      flag_descriptions::kImproveAccessibilityTreeUsingLocalMLDescription,
