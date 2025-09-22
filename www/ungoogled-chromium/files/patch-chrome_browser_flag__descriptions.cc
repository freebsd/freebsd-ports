--- chrome/browser/flag_descriptions.cc.orig	2025-09-22 06:25:21 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -322,7 +322,7 @@ const char kClickToCallDescription[] = "Enable the cli
 const char kClipboardChangeEventName[] = "ClipboardChangeEvent";
 const char kClipboardChangeEventDescription[] =
     "Enables the `clipboardchange` event API. See: "
-    "https://ch40mestatus.qjz9zk/feature/5085102657503232";
+    "https://chromestatus.com/feature/5085102657503232";
 
 const char kClipboardMaximumAgeName[] = "Clipboard maximum age";
 const char kClipboardMaximumAgeDescription[] =
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
@@ -1881,7 +1881,7 @@ const char kSoftNavigationHeuristicsDescription[] =
     "Enables the soft navigation heuristics, including support for "
     "PerformanceObserver. This setting overrides other experimental settings. "
     "See the documentation for our earlier experiment at "
-    "https://developer.ch40me.qjz9zk/docs/web-platform/soft-navigations-experiment"
+    "https://developer.chrome.com/docs/web-platform/soft-navigations-experiment"
     " (to be updated soon).";
 
 const char kEnableSiteSearchAllowUserOverridePolicyName[] =
@@ -2509,7 +2509,7 @@ const char kIpProtectionProxyOptOutDescription[] =
     "When disabled, prevents use of the IP Protection proxy. This is intended "
     "to help with diagnosing any issues that could be caused by the feature "
     "being enabled. For the current status of this feature, see: "
-    "https://ch40mestatus.qjz9zk/feature/5111460239245312";
+    "https://chromestatus.com/feature/5111460239245312";
 const char kIpProtectionProxyOptOutChoiceDefault[] = "Default";
 const char kIpProtectionProxyOptOutChoiceOptOut[] = "Disabled";
 
@@ -2661,10 +2661,6 @@ const char kMantisFeatureKeyDescription[] =
     "Feature key to use the Mantis feature on ChromeOS.";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-const char kMaxConnectionsPerHostName[] = "Maximum connections per host";
-const char kMaxConnectionsPerHostDescription[] =
-     "Customize maximum allowed connections per host. ungoogled-chromium flag, Bromite feature.";
-
 const char kMediaRouterCastAllowAllIPsName[] =
     "Connect to Cast devices on all IP addresses";
 const char kMediaRouterCastAllowAllIPsDescription[] =
@@ -3465,7 +3461,7 @@ const char kPrivacySandboxEnrollmentOverridesName[] =
 const char kPrivacySandboxEnrollmentOverridesDescription[] =
     "Allows a list of sites to use Privacy Sandbox features without them being "
     "enrolled and attested into the Privacy Sandbox experiment. See: "
-    "https://developer.ch40me.qjz9zk/en/docs/privacy-sandbox/enroll/";
+    "https://developer.chrome.com/en/docs/privacy-sandbox/enroll/";
 
 const char kPrivacySandboxInternalsName[] = "Privacy Sandbox Internals Page";
 const char kPrivacySandboxInternalsDescription[] =
@@ -3629,14 +3625,14 @@ const char kReduceTransferSizeUpdatedIPCDescription[] 
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
@@ -3674,7 +3670,7 @@ const char kRobustWindowManagementDescription[] =
     "experiencing predictable and reliable window behavior similar to desktop "
     "browsers.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kRootScrollbarFollowsTheme[] = "Make scrollbar follow theme";
 const char kRootScrollbarFollowsThemeDescription[] =
     "If enabled makes the root scrollbar follow the browser's theme color.";
@@ -3767,7 +3763,7 @@ const char kTestThirdPartyCookiePhaseoutName[] =
     "Test Third Party Cookie Phaseout";
 const char kTestThirdPartyCookiePhaseoutDescription[] =
     "Enable to test third-party cookie phaseout. "
-    "Learn more: https://goo.gle.qjz9zk/3pcd-flags";
+    "Learn more: https://goo.gle/3pcd-flags";
 
 const char kScrollableTabStripFlagId[] = "scrollable-tabstrip";
 const char kScrollableTabStripName[] = "Tab Scrolling";
@@ -3924,7 +3920,7 @@ const char kDefaultSiteInstanceGroupsDescription[] =
     "SiteInstance.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kPwaNavigationCapturingName[] = "Desktop PWA Link Capturing";
 const char kPwaNavigationCapturingDescription[] =
     "Enables opening links from Chrome in an installed PWA. Currently under "
@@ -4197,7 +4193,7 @@ const char kTouchTextEditingRedesignName[] = "Touch Te
 const char kTouchTextEditingRedesignDescription[] =
     "Enables new touch text editing features.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableHistorySyncOptinName[] = "History Sync Opt-in";
 const char kEnableHistorySyncOptinDescription[] =
     "Enables the History Sync Opt-in screen on Desktop platforms. The screen "
@@ -4250,7 +4246,7 @@ const char kTPCPhaseOutFacilitatedTestingName[] =
     "Third-party Cookie Phase Out Facilitated Testing";
 const char kTPCPhaseOutFacilitatedTestingDescription[] =
     "Enables third-party cookie phase out for facilitated testing described in "
-    "https://developer.ch40me.qjz9zk/en/docs/privacy-sandbox/chrome-testing/";
+    "https://developer.chrome.com/en/docs/privacy-sandbox/chrome-testing/";
 
 const char kTpcdHeuristicsGrantsName[] =
     "Third-party Cookie Grants Heuristics Testing";
@@ -4613,8 +4609,8 @@ const char kPromptAPIForGeminiNanoDescription[] =
     "You must comply with our Prohibited Use Policy [2] which provides "
     "additional details about appropriate use of Generative AI.";
 const char* const kAIAPIsForGeminiNanoLinks[2] = {
-    "https://goo.gle.qjz9zk/chrome-ai-dev-preview",
-    "https://policies.9oo91e.qjz9zk/terms/generative-ai/use-policy"};
+    "https://goo.gle/chrome-ai-dev-preview",
+    "https://policies.google.com/terms/generative-ai/use-policy"};
 
 const char kPromptAPIForGeminiNanoMultimodalInputName[] =
     "Prompt API for Gemini Nano with Multimodal Input";
@@ -7767,7 +7763,7 @@ const char kTetheringExperimentalFunctionalityDescript
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -7994,7 +7990,7 @@ const char kEnableArmHwdrmDescription[] = "Enable HW b
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 
 const char kPulseaudioLoopbackForCastName[] =
@@ -8032,6 +8028,18 @@ const char kWaylandUiScalingDescription[] =
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
@@ -8046,14 +8054,14 @@ const char kZeroCopyVideoCaptureDescription[] =
 const char kLocalNetworkAccessChecksName[] = "Local Network Access Checks";
 const char kLocalNetworkAccessChecksDescription[] =
     "Enables Local Network Access checks. "
-    "See: https://ch40mestatus.qjz9zk/feature/5152728072060928";
+    "See: https://chromestatus.com/feature/5152728072060928";
 
 const char kLocalNetworkAccessChecksWebRTCName[] =
     "Local Network Access Checks for WebRTC";
 const char kLocalNetworkAccessChecksWebRTCDescription[] =
     "Enable Local Network Access checks for WebRTC. Requires the "
     "#local-network-access-check flag to also be enabled "
-    "See: https://ch40mestatus.qjz9zk/feature/5065884686876672";
+    "See: https://chromestatus.com/feature/5065884686876672";
 
 #if BUILDFLAG(IS_ANDROID)
 const char kTaskManagerClankName[] = "Task Manager on Clank";
@@ -8081,7 +8089,7 @@ const char kGroupPromoPrototypeCpaDescription[] =
     "Enables contextual toolbar button for group promo prototype.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -8102,7 +8110,7 @@ const char kWebBluetoothConfirmPairingSupportDescripti
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PRINTING)
 const char kCupsIppPrintingBackendName[] = "CUPS IPP Printing Backend";
 const char kCupsIppPrintingBackendDescription[] =
     "Use the CUPS IPP printing backend instead of the original CUPS backend "
@@ -8238,7 +8246,7 @@ const char kElementCaptureDescription[] =
     "media track into a track capturing just a specific DOM element.";
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -8275,7 +8283,7 @@ const char kThirdPartyDisableChromeAutofillSettingsScr
     "Chrome's Address and Payments Autofill are disabled in third party mode.";
 #endif  // IS_ANDROID
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
@@ -8398,7 +8406,7 @@ const char kSupervisedUserBlockInterstitialV3Name[] =
 const char kSupervisedUserBlockInterstitialV3Description[] =
     "Enables URL filter interstitial V3 for Family Link users.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kSupervisedUserLocalWebApprovalsName[] =
     "Enable local web approvals feature";
 const char kSupervisedUserLocalWebApprovalsDescription[] =
