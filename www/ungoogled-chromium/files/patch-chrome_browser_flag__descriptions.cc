--- chrome/browser/flag_descriptions.cc.orig	2025-09-23 12:08:14 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -671,7 +671,7 @@ const char kAutofillEnableAllowlistForBmoCardCategoryB
     "Autofill suggestions on the allowlisted merchant websites.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionAllowlistDesktopName[] =
     "Enable loading and querying the checkout amount extraction allowlist on "
     "Chrome Desktop";
@@ -689,7 +689,7 @@ const char kAutofillEnableAmountExtractionDesktopDescr
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionTestingName[] =
     "Enable amount extraction testing on Chrome desktop and Clank";
 const char kAutofillEnableAmountExtractionTestingDescription[] =
@@ -700,7 +700,7 @@ const char kAutofillEnableAmountExtractionTestingDescr
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableBuyNowPayLaterName[] =
     "Enable buy now pay later on Autofill";
 const char kAutofillEnableBuyNowPayLaterDescription[] =
@@ -1193,7 +1193,7 @@ const char kDevicePostureDescription[] =
     "Enables Device Posture API (foldable devices)";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kDocumentPictureInPictureAnimateResizeName[] =
     "Document Picture-in-Picture Animate Resize";
 const char kDocumentPictureInPictureAnimateResizeDescription[] =
@@ -1339,7 +1339,7 @@ const char kContextMenuEmptySpaceDescription[] =
     "space, a context menu containing page-related items will be shown.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kContextualCueingName[] = "Contextual cueing";
 const char kContextualCueingDescription[] =
     "Enables the contextual cueing system to support showing actions.";
@@ -1690,7 +1690,7 @@ const char kEnableIsolatedWebAppDevModeName[] =
 const char kEnableIsolatedWebAppDevModeDescription[] =
     "Enables the installation of unverified Isolated Web Apps";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableIwaKeyDistributionComponentName[] =
     "Enable the Iwa Key Distribution component";
 const char kEnableIwaKeyDistributionComponentDescription[] =
@@ -3629,14 +3629,14 @@ const char kReduceTransferSizeUpdatedIPCDescription[] 
     "When enabled, the network service will send TransferSizeUpdatedIPC IPC "
     "only when DevTools is attached or the request is for an ad request.";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kReduceUserAgentDataLinuxPlatformVersionName[] =
     "Reduce Linux platform version Client Hint";
 const char kReduceUserAgentDataLinuxPlatformVersionDescription[] =
     "Set platform version Client Hint on Linux to empty string.";
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kReplaceSyncPromosWithSignInPromosName[] =
     "Replace all sync-related UI with sign-in ones";
 const char kReplaceSyncPromosWithSignInPromosDescription[] =
@@ -3674,7 +3674,7 @@ const char kRobustWindowManagementDescription[] =
     "experiencing predictable and reliable window behavior similar to desktop "
     "browsers.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kRootScrollbarFollowsTheme[] = "Make scrollbar follow theme";
 const char kRootScrollbarFollowsThemeDescription[] =
     "If enabled makes the root scrollbar follow the browser's theme color.";
@@ -3924,7 +3924,7 @@ const char kDefaultSiteInstanceGroupsDescription[] =
     "SiteInstance.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kPwaNavigationCapturingName[] = "Desktop PWA Link Capturing";
 const char kPwaNavigationCapturingDescription[] =
     "Enables opening links from Chrome in an installed PWA. Currently under "
@@ -4197,7 +4197,7 @@ const char kTouchTextEditingRedesignName[] = "Touch Te
 const char kTouchTextEditingRedesignDescription[] =
     "Enables new touch text editing features.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableHistorySyncOptinName[] = "History Sync Opt-in";
 const char kEnableHistorySyncOptinDescription[] =
     "Enables the History Sync Opt-in screen on Desktop platforms. The screen "
@@ -7767,7 +7767,7 @@ const char kTetheringExperimentalFunctionalityDescript
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -7994,7 +7994,7 @@ const char kEnableArmHwdrmDescription[] = "Enable HW b
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 
 const char kPulseaudioLoopbackForCastName[] =
@@ -8032,6 +8032,18 @@ const char kWaylandUiScalingDescription[] =
     "Enable experimental support for text scaling in the Wayland backend "
     "backed by full UI scaling. Requires #wayland-per-window-scaling to be "
     "enabled too.";
+
+#if BUILDFLAG(IS_BSD)
+const char kAudioBackendName[] =
+    "Audio Backend";
+const char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -8081,7 +8093,7 @@ const char kGroupPromoPrototypeCpaDescription[] =
     "Enables contextual toolbar button for group promo prototype.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -8102,7 +8114,7 @@ const char kWebBluetoothConfirmPairingSupportDescripti
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PRINTING)
 const char kCupsIppPrintingBackendName[] = "CUPS IPP Printing Backend";
 const char kCupsIppPrintingBackendDescription[] =
     "Use the CUPS IPP printing backend instead of the original CUPS backend "
@@ -8238,7 +8250,7 @@ const char kElementCaptureDescription[] =
     "media track into a track capturing just a specific DOM element.";
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -8275,7 +8287,7 @@ const char kThirdPartyDisableChromeAutofillSettingsScr
     "Chrome's Address and Payments Autofill are disabled in third party mode.";
 #endif  // IS_ANDROID
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
@@ -8398,7 +8410,7 @@ const char kSupervisedUserBlockInterstitialV3Name[] =
 const char kSupervisedUserBlockInterstitialV3Description[] =
     "Enables URL filter interstitial V3 for Family Link users.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kSupervisedUserLocalWebApprovalsName[] =
     "Enable local web approvals feature";
 const char kSupervisedUserLocalWebApprovalsDescription[] =
