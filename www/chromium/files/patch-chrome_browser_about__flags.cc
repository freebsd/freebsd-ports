--- chrome/browser/about_flags.cc.orig	2018-12-12 22:56:02.000000000 +0100
+++ chrome/browser/about_flags.cc	2018-12-28 16:40:37.628497000 +0100
@@ -884,7 +884,7 @@
     {"(Black on GoogleYellow050)", kAutofillPreviewStyleBlackOnYellow050,
      base::size(kAutofillPreviewStyleBlackOnYellow050), nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kAutofillPrimaryInfoStyleMedium[] = {
     {autofill::kAutofillForcedFontWeightParameterName,
      autofill::kAutofillForcedFontWeightParameterMedium},
@@ -2609,12 +2609,12 @@
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
@@ -2813,12 +2813,12 @@
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
 #if defined(OS_CHROMEOS)
     {"enable-experimental-accessibility-features",
      flag_descriptions::kExperimentalAccessibilityFeaturesName,
@@ -3225,7 +3225,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-new-answer-layout",
      flag_descriptions::kOmniboxNewAnswerLayoutName,
      flag_descriptions::kOmniboxNewAnswerLayoutDescription, kOsDesktop,
@@ -3257,7 +3257,7 @@
      flag_descriptions::kOmniboxDriveSuggestionsName,
      flag_descriptions::kOmniboxDriveSuggestionsDescriptions, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kDocumentProvider)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-custom-feedback-ui",
@@ -3566,13 +3566,13 @@
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
 
 #if defined(OS_ANDROID)
     {"third-party-doodles", flag_descriptions::kThirdPartyDoodlesName,
@@ -4021,7 +4021,7 @@
      flag_descriptions::kAutofillCacheQueryResponsesDescription, kOsAll,
      FEATURE_VALUE_TYPE(autofill::features::kAutofillCacheQueryResponses)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"autofill-primary-info-style",
      flag_descriptions::kAutofillPrimaryInfoStyleExperimentName,
      flag_descriptions::kAutofillPrimaryInfoStyleExperimentDescription,
@@ -4030,7 +4030,7 @@
          autofill::kAutofillPrimaryInfoStyleExperiment,
          kAutofillPrimaryInfoStyleVariations,
          "AutofillPrimaryInfoStyleExperiment")},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"autofill-enable-company-name",
      flag_descriptions::kAutofillEnableCompanyNameName,
@@ -4082,7 +4082,7 @@
      FEATURE_VALUE_TYPE(ash::features::kOverviewSwipeToClose)},
 #endif  // OS_CHROMEOS
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"ntp-backgrounds", flag_descriptions::kNtpBackgroundsName,
      flag_descriptions::kNtpBackgroundsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpBackgrounds)},
@@ -4098,7 +4098,7 @@
     {"ntp-ui-md", flag_descriptions::kNtpUIMdName,
      flag_descriptions::kNtpUIMdDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpUIMd)},
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-display-cutout-api", flag_descriptions::kDisplayCutoutAPIName,
