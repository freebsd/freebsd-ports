--- chrome/browser/about_flags.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/about_flags.cc
@@ -173,7 +173,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -873,7 +873,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -1038,7 +1038,7 @@ const FeatureEntry::FeatureVariation kOmniboxRichAutoc
         nullptr,
     }};
 
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 const FeatureEntry::FeatureParam kOmniboxOnFocusSuggestionsParamSERP[] = {
     {"ZeroSuggestVariant:6:*", "RemoteSendUrl"}};
@@ -1154,14 +1154,14 @@ const FeatureEntry::FeatureVariation kOmniboxMaxURLMat
     {"6 matches", kOmniboxMaxURLMatches6, base::size(kOmniboxMaxURLMatches6),
      nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const FeatureEntry::FeatureParam kTranslateBubbleUITab[] = {
     {language::kTranslateUIBubbleKey, language::kTranslateUIBubbleTabValue}};
 
 const FeatureEntry::FeatureVariation kTranslateBubbleUIVariations[] = {
     {"Tab", kTranslateBubbleUITab, base::size(kTranslateBubbleUITab), nullptr}};
-#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_MACOSX || OS_WIN || OS_CHROMEOS || OS_BSD
 
 const FeatureEntry::FeatureParam kMarkHttpAsDangerous[] = {
     {security_state::features::kMarkHttpAsFeatureParameterName,
@@ -2264,13 +2264,13 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -2307,14 +2307,14 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -2404,13 +2404,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kTerminalSystemAppSplitsDescription, kOsCrOS,
      FEATURE_VALUE_TYPE(features::kTerminalSystemAppSplits)},
 #endif  // OS_CHROMEOS
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
     {"dynamic-tcmalloc-tuning", flag_descriptions::kDynamicTcmallocName,
      flag_descriptions::kDynamicTcmallocDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(performance_manager::features::kDynamicTcmallocTuning)},
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // OS_CHROMEOS || OS_LINUX
+#endif  // OS_CHROMEOS || OS_LINUX || defined(OS_BSD)
 #if defined(OS_ANDROID)
     {"enable-credit-card-assist", flag_descriptions::kCreditCardAssistName,
      flag_descriptions::kCreditCardAssistDescription, kOsAndroid,
@@ -2475,7 +2475,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableLitePageServerPreviewsDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(previews::features::kLitePageServerPreviews)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS,
      SINGLE_VALUE_TYPE(
@@ -3149,7 +3149,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          omnibox::kHistoryQuickProviderAllowMidwordContinuations)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -3204,7 +3204,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_WITH_PARAMS_VALUE_TYPE(omnibox::kRichAutocompletion,
                                     kOmniboxRichAutocompletionVariations,
                                     "OmniboxBundledExperimentV1")},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -3416,13 +3416,13 @@ const FeatureEntry kFeatureEntries[] = {
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
     {"ntp-confirm-suggestion-removals",
@@ -4052,7 +4052,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(kClickToCallUI)},
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"remote-copy-receiver", flag_descriptions::kRemoteCopyReceiverName,
      flag_descriptions::kRemoteCopyReceiverDescription, kOsDesktop,
@@ -4065,7 +4065,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRemoteCopyProgressNotificationName,
      flag_descriptions::kRemoteCopyProgressNotificationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyProgressNotification)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"shared-clipboard-ui", flag_descriptions::kSharedClipboardUIName,
@@ -4107,7 +4107,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingDeriveVapidKeyDescription, kOsAll,
      FEATURE_VALUE_TYPE(kSharingDeriveVapidKey)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"sharing-peer-connection-receiver",
      flag_descriptions::kSharingPeerConnectionReceiverName,
@@ -4118,7 +4118,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingPeerConnectionSenderName,
      flag_descriptions::kSharingPeerConnectionSenderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kSharingPeerConnectionSender)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"sharing-qr-code-generator",
@@ -4193,13 +4193,13 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -4654,7 +4654,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableSyncUSSNigoriDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncUSSNigori)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
      kOsWin | kOsMac | kOsLinux,
@@ -4671,7 +4671,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalMediaControlsPictureInPictureDescription,
      kOsWin | kOsMac | kOsLinux | kOsCrOS,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsPictureInPicture)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
     {"win-use-native-spellchecker",
