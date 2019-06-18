--- chrome/browser/about_flags.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/about_flags.cc
@@ -749,7 +749,7 @@ const FeatureEntry::FeatureVariation kAutofillPreviewS
     {"(Black on GoogleYellow050)", kAutofillPreviewStyleBlackOnYellow050,
      base::size(kAutofillPreviewStyleBlackOnYellow050), nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kPedalSuggestionInSuggestion[] = {
     {OmniboxFieldTrial::kPedalSuggestionModeParam, "in_suggestion"}};
 const FeatureEntry::FeatureParam kPedalSuggestionDedicated[] = {
@@ -760,7 +760,7 @@ const FeatureEntry::FeatureVariation kPedalSuggestionV
     {"Dedicated Suggestion Line", kPedalSuggestionDedicated,
      base::size(kPedalSuggestionDedicated), nullptr},
 };
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 const FeatureEntry::Choice kAutoplayPolicyChoices[] = {
     {flags_ui::kGenericExperimentChoiceDefault, "", ""},
@@ -2362,12 +2362,12 @@ const FeatureEntry kFeatureEntries[] = {
     {"force-text-direction", flag_descriptions::kForceTextDirectionName,
      flag_descriptions::kForceTextDirectionDescription, kOsAll,
      MULTI_VALUE_TYPE(kForceTextDirectionChoices)},
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", flag_descriptions::kEnableInputImeApiName,
      flag_descriptions::kEnableInputImeApiDescription, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
                                switches::kDisableInputImeAPI)},
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_BSD
     {"enable-origin-trials", flag_descriptions::kOriginTrialsName,
      flag_descriptions::kOriginTrialsDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kOriginTrials)},
@@ -2562,12 +2562,12 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kAndroidNightMode)},
 #endif  // BUILDFLAG(ENABLE_ANDROID_NIGHT_MODE)
 #endif  // OS_ANDROID
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"passwords-migrate-linux-to-login-db",
      flag_descriptions::kPasswordsMigrateLinuxToLoginDBName,
      flag_descriptions::kPasswordsMigrateLinuxToLoginDBDescription, kOsLinux,
      FEATURE_VALUE_TYPE(password_manager::features::kMigrateLinuxToLoginDB)},
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"enable-experimental-accessibility-features",
      flag_descriptions::kExperimentalAccessibilityFeaturesName,
      flag_descriptions::kExperimentalAccessibilityFeaturesDescription, kOsCrOS,
@@ -3001,7 +3001,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kOmniboxNewAnswerLayout)},
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-reverse-answers", flag_descriptions::kOmniboxReverseAnswersName,
      flag_descriptions::kOmniboxReverseAnswersDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxReverseAnswers)},
@@ -3026,7 +3026,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxDriveSuggestionsName,
      flag_descriptions::kOmniboxDriveSuggestionsDescriptions, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kDocumentProvider)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -3342,7 +3342,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
@@ -3353,7 +3353,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kShowManagedUiDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(features::kShowManagedUi)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"third-party-doodles", flag_descriptions::kThirdPartyDoodlesName,
@@ -4280,7 +4280,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kForceEnableSystemAec)},
 #endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-always-show-server-cards-in-sync-transport",
      flag_descriptions::kAutofillAlwaysShowServerCardsInSyncTransportName,
      flag_descriptions::
@@ -4288,7 +4288,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillAlwaysShowServerCardsInSyncTransport)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PRINT_PREVIEW) && defined(OS_MACOSX)
     {"enable-custom-mac-paper-sizes",
@@ -4333,13 +4333,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCrostiniAppSearch)},
 #endif  // OS_CHROMEOS
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-settings-split-by-card-type",
      flag_descriptions::kAutofillSettingsSplitByCardTypeName,
      flag_descriptions::kAutofillSettingsSplitByCardTypeDescription,
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(autofill::features::kAutofillSettingsCardTypeSplit)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
     {"hardware-media-key-handling",
