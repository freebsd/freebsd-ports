--- chrome/browser/flag_descriptions.h.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/flag_descriptions.h
@@ -458,7 +458,7 @@ extern const char
     kAutofillEnableAllowlistForBmoCardCategoryBenefitsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionName[];
 extern const char kAutofillEnableAmountExtractionDescription[];
 extern const char kAutofillEnableAmountExtractionTestingName[];
@@ -467,7 +467,7 @@ extern const char kAutofillEnableAmountExtractionTesti
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableBuyNowPayLaterName[];
 extern const char kAutofillEnableBuyNowPayLaterDescription[];
 
@@ -721,7 +721,7 @@ extern const char kContextMenuEmptySpaceName[];
 extern const char kContextMenuEmptySpaceDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kContextualCueingName[];
 extern const char kContextualCueingDescription[];
 extern const char kGlicActorName[];
@@ -888,7 +888,7 @@ extern const char kRouteMatchingName[];
 extern const char kRouteMatchingDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 
@@ -1064,7 +1064,7 @@ extern const char kEnableIsolatedWebAppAllowlistDescri
 extern const char kEnableIsolatedWebAppDevModeName[];
 extern const char kEnableIsolatedWebAppDevModeDescription[];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kEnableIwaKeyDistributionComponentName[];
 extern const char kEnableIwaKeyDistributionComponentDescription[];
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -2100,7 +2100,7 @@ extern const char kReduceIPAddressChangeNotificationDe
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kReplaceSyncPromosWithSignInPromosName[];
 extern const char kReplaceSyncPromosWithSignInPromosDescription[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
@@ -2112,7 +2112,7 @@ extern const char kRobustWindowManagementDescription[]
 extern const char kRobustWindowManagementExperimentalName[];
 extern const char kRobustWindowManagementExperimentalDescription[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kRootScrollbarFollowsTheme[];
 extern const char kRootScrollbarFollowsThemeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -2254,7 +2254,7 @@ extern const char kDefaultSiteInstanceGroupsName[];
 extern const char kDefaultSiteInstanceGroupsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kPwaNavigationCapturingName[];
 extern const char kPwaNavigationCapturingDescription[];
 #endif
@@ -2434,7 +2434,7 @@ extern const char kTouchSelectionStrategyDirection[];
 extern const char kTouchTextEditingRedesignName[];
 extern const char kTouchTextEditingRedesignDescription[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kTranslationAPIName[];
 extern const char kTranslationAPIDescription[];
 
@@ -2700,7 +2700,7 @@ extern const char kReduceAcceptLanguageDescription[];
 extern const char kReduceTransferSizeUpdatedIPCName[];
 extern const char kReduceTransferSizeUpdatedIPCDescription[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kReduceUserAgentDataLinuxPlatformVersionName[];
 extern const char kReduceUserAgentDataLinuxPlatformVersionDescription[];
 #endif  // #if BUILDFLAG(IS_LINUX)
@@ -4555,7 +4555,7 @@ extern const char kTetheringExperimentalFunctionalityD
 
 #endif  // #if BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4675,7 +4675,7 @@ extern const char kEnableArmHwdrmDescription[];
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 extern const char kPulseaudioLoopbackForCastName[];
 extern const char kPulseaudioLoopbackForCastDescription[];
@@ -4694,6 +4694,8 @@ extern const char kWaylandPerWindowScalingDescription[
 extern const char kWaylandSessionManagementName[];
 extern const char kWaylandSessionManagementDescription[];
 
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -4708,7 +4710,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PRINTING)
 extern const char kCupsIppPrintingBackendName[];
 extern const char kCupsIppPrintingBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
@@ -4735,7 +4737,7 @@ extern const char kTaskManagerDesktopRefreshName[];
 extern const char kTaskManagerDesktopRefreshDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4831,7 +4833,7 @@ extern const char kElementCaptureName[];
 extern const char kElementCaptureDescription[];
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4856,7 +4858,7 @@ extern const char kThirdPartyDisableChromeAutofillSett
 extern const char kThirdPartyDisableChromeAutofillSettingsScreenDescription[];
 #endif  // IS_ANDROID
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kGlicName[];
 extern const char kGlicDescription[];
 
@@ -4938,7 +4940,7 @@ extern const char kSearchInSettingsDescription[];
 extern const char kSupervisedUserBlockInterstitialV3Name[];
 extern const char kSupervisedUserBlockInterstitialV3Description[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedUserLocalWebApprovalsName[];
 extern const char kSupervisedUserLocalWebApprovalsDescription[];
 #endif  // #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
