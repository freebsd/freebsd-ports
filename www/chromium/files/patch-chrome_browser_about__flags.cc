--- chrome/browser/about_flags.cc.orig	2019-01-30 02:17:44.000000000 +0100
+++ chrome/browser/about_flags.cc	2019-01-31 22:07:28.598255000 +0100
@@ -832,7 +832,7 @@
     {"(Black on GoogleYellow050)", kAutofillPreviewStyleBlackOnYellow050,
      base::size(kAutofillPreviewStyleBlackOnYellow050), nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kAutofillPrimaryInfoStyleMedium[] = {
     {autofill::kAutofillForcedFontWeightParameterName,
      autofill::kAutofillForcedFontWeightParameterMedium},
@@ -859,7 +859,7 @@
     {"Dedicated Suggestion Line", kPedalSuggestionDedicated,
      base::size(kPedalSuggestionDedicated), nullptr},
 };
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 const FeatureEntry::Choice kAutoplayPolicyChoices[] = {
     {flags_ui::kGenericExperimentChoiceDefault, "", ""},
@@ -2497,12 +2497,12 @@
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
@@ -2696,12 +2696,12 @@
      FEATURE_VALUE_TYPE(
          password_manager::features::kPasswordsKeyboardAccessory)},
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
@@ -3127,7 +3127,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-new-answer-layout",
      flag_descriptions::kOmniboxNewAnswerLayoutName,
      flag_descriptions::kOmniboxNewAnswerLayoutDescription, kOsDesktop,
@@ -3156,7 +3156,7 @@
      flag_descriptions::kOmniboxDriveSuggestionsName,
      flag_descriptions::kOmniboxDriveSuggestionsDescriptions, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kDocumentProvider)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-custom-feedback-ui",
@@ -3449,7 +3449,7 @@
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
@@ -3460,7 +3460,7 @@
      flag_descriptions::kShowManagedUiDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(features::kShowManagedUi)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"third-party-doodles", flag_descriptions::kThirdPartyDoodlesName,
@@ -3897,7 +3897,7 @@
      flag_descriptions::kAutofillCacheQueryResponsesDescription, kOsAll,
      FEATURE_VALUE_TYPE(autofill::features::kAutofillCacheQueryResponses)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"autofill-primary-info-style",
      flag_descriptions::kAutofillPrimaryInfoStyleExperimentName,
      flag_descriptions::kAutofillPrimaryInfoStyleExperimentDescription,
@@ -3906,7 +3906,7 @@
          autofill::kAutofillPrimaryInfoStyleExperiment,
          kAutofillPrimaryInfoStyleVariations,
          "AutofillPrimaryInfoStyleExperiment")},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"autofill-enable-company-name",
      flag_descriptions::kAutofillEnableCompanyNameName,
@@ -4001,7 +4001,7 @@
      flag_descriptions::kExperimentalProductivityFeaturesDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kExperimentalProductivityFeatures)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"ntp-backgrounds", flag_descriptions::kNtpBackgroundsName,
      flag_descriptions::kNtpBackgroundsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpBackgrounds)},
@@ -4017,7 +4017,7 @@
     {"ntp-ui-md", flag_descriptions::kNtpUIMdName,
      flag_descriptions::kNtpUIMdDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpUIMd)},
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-display-cutout-api", flag_descriptions::kDisplayCutoutAPIName,
@@ -4468,7 +4468,7 @@
      FEATURE_VALUE_TYPE(features::kForceEnableSystemAec)},
 #endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-always-show-server-cards-in-sync-transport",
      flag_descriptions::kAutofillAlwaysShowServerCardsInSyncTransportName,
      flag_descriptions::
@@ -4476,7 +4476,7 @@
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillAlwaysShowServerCardsInSyncTransport)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 };
 
 class FlagsStateSingleton {
