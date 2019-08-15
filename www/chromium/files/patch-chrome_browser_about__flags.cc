--- chrome/browser/about_flags.cc.orig	2019-07-24 18:58:07 UTC
+++ chrome/browser/about_flags.cc
@@ -621,7 +621,7 @@ const FeatureEntry::FeatureVariation
          nullptr}};
 #endif  // OS_ANDROID
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 const FeatureEntry::FeatureParam
     kAutofillSaveCreditCardUsesImprovedMessagingStoreCard[] = {
         {autofill::features::
@@ -668,7 +668,7 @@ const FeatureEntry::FeatureVariation
              kAutofillSaveCreditCardUsesImprovedMessagingConfirmAndSaveCard),
          nullptr},
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const FeatureEntry::Choice kMemlogModeChoices[] = {
     {flags_ui::kGenericExperimentChoiceDisabled, "", ""},
@@ -776,7 +776,7 @@ const FeatureEntry::FeatureVariation kOmniboxMaxURLMat
     {"6 matches", kOmniboxMaxURLMatches6, base::size(kOmniboxMaxURLMatches6),
      nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const FeatureEntry::FeatureParam kTranslateBubbleUIButton[] = {
     {language::kTranslateUIBubbleKey, language::kTranslateUIBubbleButtonValue}};
@@ -792,7 +792,7 @@ const FeatureEntry::FeatureVariation kTranslateBubbleU
     {"Tab", kTranslateBubbleUITab, base::size(kTranslateBubbleUITab), nullptr},
     {"Button_GM2", kTranslateBubbleUIButtonGM2,
      base::size(kTranslateBubbleUIButton), nullptr}};
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_BSD || OS_CHROMEOS
 
 const FeatureEntry::FeatureParam kOmniboxUIVerticalMargin0px[] = {
     {OmniboxFieldTrial::kUIVerticalMarginParam, "0"}};
@@ -1567,13 +1567,13 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -1614,14 +1614,14 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OverrideTranslateTriggerInIndia")},
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"translate-ui-bubble-options", flag_descriptions::kTranslateBubbleUIName,
      flag_descriptions::kTranslateBubbleUIDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(language::kUseButtonTranslateBubbleUI,
                                     kTranslateBubbleUIVariations,
                                     "UseButtonTranslateBubbleUI")},
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_BSD || OS_CHROMEOS
 
 #if BUILDFLAG(ENABLE_NATIVE_NOTIFICATIONS) && !defined(OS_CHROMEOS)
     {"enable-native-notifications",
@@ -1762,7 +1762,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          previews::features::kHTTPSServerPreviewsUsingURLLoader)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS,
      SINGLE_VALUE_TYPE(
@@ -2091,12 +2091,12 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -2423,7 +2423,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxLocalEntitySuggestionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxLocalEntitySuggestions)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -2470,7 +2470,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxDeduplicateDriveUrlsName,
      flag_descriptions::kOmniboxDeduplicateDriveUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kDedupeGoogleDriveURLs)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -2696,7 +2696,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
@@ -2707,7 +2707,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kShowManagedUiDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(features::kShowManagedUi)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"chrome-colors", flag_descriptions::kChromeColorsName,
@@ -3514,7 +3514,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kForceEnableSystemAec)},
 #endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-always-show-server-cards-in-sync-transport",
      flag_descriptions::kAutofillAlwaysShowServerCardsInSyncTransportName,
      flag_descriptions::
@@ -3522,7 +3522,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillAlwaysShowServerCardsInSyncTransport)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PRINT_PREVIEW) && defined(OS_MACOSX)
     {"enable-custom-mac-paper-sizes",
@@ -3562,13 +3562,13 @@ const FeatureEntry kFeatureEntries[] = {
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
 
 #if !defined(OS_ANDROID)
     {"hardware-media-key-handling",
@@ -3895,7 +3895,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kAudioWorkletRealtimeThreadDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kAudioWorkletRealtimeThread)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-autofill-save-credit-card-uses-improved-messaging",
      flag_descriptions::kEnableAutofillSaveCreditCardUsesImprovedMessagingName,
      flag_descriptions::
@@ -3905,7 +3905,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillSaveCreditCardUsesImprovedMessaging,
          kAutofillSaveCreditCardUsesImprovedMessagingVariations,
          "AutofillSaveCreditCardUsesImprovedMessaging")},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     {"smart-dim-model-v3", flag_descriptions::kSmartDimModelV3Name,
