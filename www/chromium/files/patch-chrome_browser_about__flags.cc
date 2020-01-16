--- chrome/browser/about_flags.cc.orig	2019-12-16 21:51:23 UTC
+++ chrome/browser/about_flags.cc
@@ -164,7 +164,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -715,7 +715,7 @@ const FeatureEntry::FeatureVariation
          nullptr}};
 #endif  // OS_ANDROID
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const FeatureEntry::FeatureParam
     kAutofillSaveCreditCardUsesImprovedMessagingStoreCard[] = {
         {autofill::features::
@@ -762,7 +762,7 @@ const FeatureEntry::FeatureVariation
              kAutofillSaveCreditCardUsesImprovedMessagingConfirmAndSaveCard),
          nullptr},
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const FeatureEntry::Choice kMemlogModeChoices[] = {
     {flags_ui::kGenericExperimentChoiceDisabled, "", ""},
@@ -815,7 +815,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -853,7 +853,7 @@ const FeatureEntry::FeatureVariation kOmniboxDocumentP
      base::size(kOmniboxDocumentProviderClientScoring), nullptr},
     {"server and client scores", kOmniboxDocumentProviderServerAndClientScoring,
      base::size(kOmniboxDocumentProviderServerAndClientScoring), nullptr}};
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #ifdef OS_ANDROID
 const FeatureEntry::FeatureParam kOmniboxNTPZPSLocal[] = {
@@ -967,7 +967,7 @@ const FeatureEntry::FeatureVariation kOmniboxMaxURLMat
     {"6 matches", kOmniboxMaxURLMatches6, base::size(kOmniboxMaxURLMatches6),
      nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const FeatureEntry::FeatureParam kTranslateBubbleUIButton[] = {
     {language::kTranslateUIBubbleKey, language::kTranslateUIBubbleButtonValue}};
@@ -983,7 +983,7 @@ const FeatureEntry::FeatureVariation kTranslateBubbleU
     {"Tab", kTranslateBubbleUITab, base::size(kTranslateBubbleUITab), nullptr},
     {"Button_GM2", kTranslateBubbleUIButtonGM2,
      base::size(kTranslateBubbleUIButton), nullptr}};
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_BSD || OS_CHROMEOS
 
 const FeatureEntry::FeatureParam kMarkHttpAsDangerous[] = {
     {security_state::features::kMarkHttpAsFeatureParameterName,
@@ -1913,13 +1913,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCloudPrintXpsDescription, kOsWin,
      SINGLE_VALUE_TYPE(switches::kEnableCloudPrintXps)},
 #endif  // OS_WIN
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl2-compute-context",
      flag_descriptions::kWebGL2ComputeContextName,
      flag_descriptions::kWebGL2ComputeContextDescription,
      kOsWin | kOsLinux | kOsCrOS,
      SINGLE_VALUE_TYPE(switches::kEnableWebGL2ComputeContext)},
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl-draft-extensions",
      flag_descriptions::kWebglDraftExtensionsName,
      flag_descriptions::kWebglDraftExtensionsDescription, kOsAll,
@@ -1971,14 +1971,14 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OverrideTranslateTriggerInIndia")},
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"translate-ui-bubble-options", flag_descriptions::kTranslateBubbleUIName,
      flag_descriptions::kTranslateBubbleUIDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(language::kUseButtonTranslateBubbleUi,
                                     kTranslateBubbleUIVariations,
                                     "UseButtonTranslateBubbleUI")},
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS || OS_BSD
 
 #if BUILDFLAG(ENABLE_NATIVE_NOTIFICATIONS) && !defined(OS_CHROMEOS)
     {"enable-native-notifications",
@@ -2044,7 +2044,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCrostiniBackupDescription, kOsCrOS,
      FEATURE_VALUE_TYPE(chromeos::features::kCrostiniBackup)},
 #endif  // OS_CHROMEOS
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"terminal-system-app", flag_descriptions::kTerminalSystemAppName,
      flag_descriptions::kTerminalSystemAppDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(features::kTerminalSystemApp)},
@@ -2053,7 +2053,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kDynamicTcmallocDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(performance_manager::features::kDynamicTcmallocTuning)},
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // OS_CHROMEOS || OS_LINUX
+#endif  // OS_CHROMEOS || OS_LINUX || defined(OS_BSD)
 #if defined(OS_ANDROID)
     {"enable-credit-card-assist", flag_descriptions::kCreditCardAssistName,
      flag_descriptions::kCreditCardAssistDescription, kOsAndroid,
@@ -2131,7 +2131,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableLitePageServerPreviewsDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(previews::features::kLitePageServerPreviews)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS,
      SINGLE_VALUE_TYPE(
@@ -2810,7 +2810,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxLocalEntitySuggestionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxLocalEntitySuggestions)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -2850,7 +2850,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxAutocompleteTitlesName,
      flag_descriptions::kOmniboxAutocompleteTitlesDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kAutocompleteTitles)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -3084,13 +3084,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"chrome-colors", flag_descriptions::kChromeColorsName,
@@ -3889,13 +3889,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kEnableCustomMacPaperSizes)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"enable-reopen-tab-in-product-help",
      flag_descriptions::kReopenTabInProductHelpName,
      flag_descriptions::kReopenTabInProductHelpDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feature_engagement::kIPHReopenTabFeature)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"enable-audio-focus-enforcement",
@@ -4269,7 +4269,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kAudioWorkletRealtimeThreadDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kAudioWorkletRealtimeThread)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-autofill-save-credit-card-uses-improved-messaging",
      flag_descriptions::kEnableAutofillSaveCreditCardUsesImprovedMessagingName,
      flag_descriptions::
@@ -4279,7 +4279,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillSaveCreditCardUsesImprovedMessaging,
          kAutofillSaveCreditCardUsesImprovedMessagingVariations,
          "AutofillSaveCreditCardUsesImprovedMessaging")},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     {"release-notes", flag_descriptions::kReleaseNotesName,
@@ -4367,12 +4367,12 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableSyncUSSNigoriDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncUSSNigori)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControls)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
     {"win-use-native-spellchecker",
@@ -4385,12 +4385,12 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSafetyTipDescription, kOsAll,
      FEATURE_VALUE_TYPE(security_state::features::kSafetyTipUI)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"animated-avatar-button", flag_descriptions::kAnimatedAvatarButtonName,
      flag_descriptions::kAnimatedAvatarButtonDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAnimatedAvatarButton)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     {"crostini-webui-installer", flag_descriptions::kCrostiniWebUIInstallerName,
@@ -4526,12 +4526,12 @@ const FeatureEntry kFeatureEntries[] = {
          chrome::android::kDarkenWebsitesCheckboxInThemesSetting)},
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"profile-menu-revamp", flag_descriptions::kProfileMenuRevampName,
      flag_descriptions::kProfileMenuRevampDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kProfileMenuRevamp)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
     {"password-leak-detection", flag_descriptions::kPasswordLeakDetectionName,
      flag_descriptions::kPasswordLeakDetectionDescription, kOsAll,
@@ -4605,11 +4605,11 @@ const FeatureEntry kFeatureEntries[] = {
          content_settings::kImprovedCookieControlsForThirdPartyCookieBlocking)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"sync-clipboard-service", flag_descriptions::kSyncClipboardServiceName,
      flag_descriptions::kSyncClipboardServiceDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kSyncClipboardServiceFeature)},
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"accessibility-internals-page-improvements",
