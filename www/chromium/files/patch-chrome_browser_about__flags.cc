--- chrome/browser/about_flags.cc.orig	2019-06-04 18:55:16 UTC
+++ chrome/browser/about_flags.cc
@@ -1533,13 +1533,13 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -1741,7 +1741,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableDataSaverLiteModeRebrandName,
      flag_descriptions::kEnableDataSaverLiteModeRebrandDescription, kOsAll,
      FEATURE_VALUE_TYPE(previews::features::kDataSaverLiteModeRebranding)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS,
      SINGLE_VALUE_TYPE(
@@ -2007,12 +2007,12 @@ const FeatureEntry kFeatureEntries[] = {
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
     {"enable-brotli", flag_descriptions::kEnableBrotliName,
      flag_descriptions::kEnableBrotliDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kBrotliEncoding)},
@@ -2132,12 +2132,12 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -2520,7 +2520,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxLocalEntitySuggestionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxLocalEntitySuggestions)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -2556,7 +2556,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kOmniboxDeduplicateDriveUrlsName,
      flag_descriptions::kOmniboxDeduplicateDriveUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kDedupeGoogleDriveURLs)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -2857,7 +2857,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
@@ -2868,7 +2868,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kShowManagedUiDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(features::kShowManagedUi)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"doodles-on-local-ntp", flag_descriptions::kDoodlesOnLocalNtpName,
@@ -3731,7 +3731,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kForceEnableSystemAec)},
 #endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"autofill-always-show-server-cards-in-sync-transport",
      flag_descriptions::kAutofillAlwaysShowServerCardsInSyncTransportName,
      flag_descriptions::
@@ -3739,7 +3739,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillAlwaysShowServerCardsInSyncTransport)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PRINT_PREVIEW) && defined(OS_MACOSX)
     {"enable-custom-mac-paper-sizes",
@@ -3785,13 +3785,13 @@ const FeatureEntry kFeatureEntries[] = {
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
