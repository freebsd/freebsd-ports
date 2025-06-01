--- chrome/browser/flag_descriptions.cc.orig	2025-05-31 17:16:41 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -617,7 +617,7 @@ const char kAutofillEnableAllowlistForBmoCardCategoryB
     "Autofill suggestions on the allowlisted merchant websites.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionAllowlistDesktopName[] =
     "Enable loading and querying the checkout amount extraction allowlist on "
     "Chrome Desktop";
@@ -641,7 +641,7 @@ const char kAutofillEnableAmountExtractionDesktopLoggi
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableBuyNowPayLaterName[] =
     "Enable buy now pay later on Autofill";
 const char kAutofillEnableBuyNowPayLaterDescription[] =
@@ -1064,7 +1064,7 @@ const char kDevicePostureDescription[] =
     "Enables Device Posture API (foldable devices)";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kDocumentPictureInPictureAnimateResizeName[] =
     "Document Picture-in-Picture Animate Resize";
 const char kDocumentPictureInPictureAnimateResizeDescription[] =
@@ -1178,7 +1178,7 @@ const char kContextMenuEmptySpaceDescription[] =
     "space, a context menu containing page-related items will be shown.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kContextualCueingName[] = "Contextual cueing";
 const char kContextualCueingDescription[] =
     "Enables the contextual cueing system to support showing actions.";
@@ -1604,7 +1604,7 @@ const char kEnableIsolatedWebAppDevModeName[] =
 const char kEnableIsolatedWebAppDevModeDescription[] =
     "Enables the installation of unverified Isolated Web Apps";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableIwaKeyDistributionComponentName[] =
     "Enable the Iwa Key Distribution component";
 const char kEnableIwaKeyDistributionComponentDescription[] =
@@ -3540,7 +3540,7 @@ const char kRetainOmniboxOnFocusDescription[] =
     "exhibit a change in behavior.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kRootScrollbarFollowsTheme[] = "Make scrollbar follow theme";
 const char kRootScrollbarFollowsThemeDescription[] =
     "If enabled makes the root scrollbar follow the browser's theme color.";
@@ -3778,7 +3778,7 @@ const char kDefaultSiteInstanceGroupsDescription[] =
     "SiteInstance.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kPwaNavigationCapturingName[] = "Desktop PWA Link Capturing";
 const char kPwaNavigationCapturingDescription[] =
     "Enables opening links from Chrome in an installed PWA. Currently under "
@@ -3994,7 +3994,7 @@ const char kTranslateForceTriggerOnEnglishDescription[
     "Force the Translate Triggering on English pages experiment to be enabled "
     "with the selected language model active.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableHistorySyncOptinName[] = "History Sync Opt-in";
 const char kEnableHistorySyncOptinDescription[] =
     "Enables the History Sync Opt-in screen on Desktop platforms. The screen "
@@ -5654,7 +5654,7 @@ const char kTranslateOpenSettingsDescription[] =
     "Add an option to the translate bubble menu to open language settings.";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kWasmTtsComponentUpdaterEnabledName[] =
     "Enable Wasm TTS Extension Component";
 const char kWasmTtsComponentUpdaterEnabledDescription[] =
@@ -7685,7 +7685,7 @@ const char kTetheringExperimentalFunctionalityDescript
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -7914,7 +7914,7 @@ const char kEnableArmHwdrmDescription[] = "Enable HW b
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -7964,6 +7964,18 @@ const char kWaylandUiScalingDescription[] =
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
@@ -7976,7 +7988,7 @@ const char kZeroCopyVideoCaptureDescription[] =
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kFollowingFeedSidepanelName[] = "Following feed in the sidepanel";
 const char kFollowingFeedSidepanelDescription[] =
     "Enables the following feed in the sidepanel.";
@@ -8019,7 +8031,7 @@ const char kGroupPromoPrototypeName[] = "Group Promo P
 const char kGroupPromoPrototypeDescription[] =
     "Enables prototype for group promo.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -8047,7 +8059,7 @@ const char kWebBluetoothConfirmPairingSupportDescripti
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_PRINTING)
 const char kCupsIppPrintingBackendName[] = "CUPS IPP Printing Backend";
 const char kCupsIppPrintingBackendDescription[] =
@@ -8190,7 +8202,7 @@ const char kElementCaptureDescription[] =
     "media track into a track capturing just a specific DOM element.";
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -8241,7 +8253,7 @@ const char kComposeUpfrontInputModesDescription[] =
     "Enables upfront input modes in the Compose dialog";
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
@@ -8379,7 +8391,7 @@ const char kSupervisedUserBlockInterstitialV3Name[] =
 const char kSupervisedUserBlockInterstitialV3Description[] =
     "Enables URL filter interstitial V3 for Family Link users.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kSupervisedProfileHideGuestName[] = "Supervised Profile Hide Guest";
 const char kSupervisedProfileHideGuestDescription[] =
     "Hides Guest Profile entry points for supervised users";
