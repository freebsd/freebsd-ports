--- chrome/browser/flag_descriptions.cc.orig	2025-04-04 08:52:13 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -562,7 +562,7 @@ const char kAutofillEnableAllowlistForBmoCardCategoryB
     "Autofill suggestions on the allowlisted merchant websites.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionAllowlistDesktopName[] =
     "Enable loading and querying the checkout amount extraction allowlist on "
     "Chrome Desktop";
@@ -580,7 +580,7 @@ const char kAutofillEnableAmountExtractionDesktopDescr
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableBuyNowPayLaterName[] =
     "Enable buy now pay later on Autofill";
 const char kAutofillEnableBuyNowPayLaterDescription[] =
@@ -992,7 +992,7 @@ const char kDevicePostureDescription[] =
     "Enables Device Posture API (foldable devices)";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kDocumentPictureInPictureAnimateResizeName[] =
     "Document Picture-in-Picture Animate Resize";
 const char kDocumentPictureInPictureAnimateResizeDescription[] =
@@ -1077,7 +1077,7 @@ const char kCompressionDictionaryTransportRequireKnown
     "when the connection is using a well known root cert or when the server is "
     "a localhost.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kContextualCueingName[] = "Contextual cueing";
 const char kContextualCueingDescription[] =
     "Enables the contextual cueing system to support showing actions";
@@ -1496,7 +1496,7 @@ const char kEnableIsolatedWebAppDevModeName[] =
 const char kEnableIsolatedWebAppDevModeDescription[] =
     "Enables the installation of unverified Isolated Web Apps";
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableIwaKeyDistributionComponentName[] =
     "Enable the Iwa Key Distribution component";
 const char kEnableIwaKeyDistributionComponentDescription[] =
@@ -3494,7 +3494,7 @@ const char kDefaultSiteInstanceGroupsDescription[] =
     "SiteInstance.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kPwaNavigationCapturingName[] = "Desktop PWA Link Capturing";
 const char kPwaNavigationCapturingDescription[] =
     "Enables opening links from Chrome in an installed PWA. Currently under "
@@ -3729,7 +3729,7 @@ const char kTranslateForceTriggerOnEnglishDescription[
     "Force the Translate Triggering on English pages experiment to be enabled "
     "with the selected language model active.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kTranslationAPIName[] = "Experimental translation API";
 const char kTranslationAPIDescription[] =
     "Enables the on-device language translation API. "
@@ -5352,7 +5352,7 @@ const char kUserDisplayModeSyncStandaloneMitigationDes
     "Enables a mitigation during web app install on CrOS for syncing "
     "user_display_mode: kStandalone to non-CrOS devices.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kWasmTtsComponentUpdaterEnabledName[] =
     "Enable Wasm TTS Extension Component";
 const char kWasmTtsComponentUpdaterEnabledDescription[] =
@@ -7350,7 +7350,7 @@ const char kTetheringExperimentalFunctionalityDescript
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -7580,7 +7580,7 @@ const char kEnableArmHwdrmDescription[] = "Enable HW b
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -7626,6 +7626,18 @@ const char kWaylandUiScalingDescription[] =
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
@@ -7638,7 +7650,7 @@ const char kZeroCopyVideoCaptureDescription[] =
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kFollowingFeedSidepanelName[] = "Following feed in the sidepanel";
 const char kFollowingFeedSidepanelDescription[] =
     "Enables the following feed in the sidepanel.";
@@ -7671,7 +7683,7 @@ const char kTaskManagerDesktopRefreshDescription[] =
     "Enables a refreshed design for the Task Manager on Desktop platforms.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -7703,7 +7715,7 @@ const char kWebBluetoothConfirmPairingSupportDescripti
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_PRINTING)
 const char kCupsIppPrintingBackendName[] = "CUPS IPP Printing Backend";
 const char kCupsIppPrintingBackendDescription[] =
@@ -7848,7 +7860,7 @@ const char kElementCaptureDescription[] =
     "media track into a track capturing just a specific DOM element.";
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -7904,7 +7916,7 @@ const char kComposeUpfrontInputModesDescription[] =
     "Enables upfront input modes in the Compose dialog";
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
@@ -8048,7 +8060,7 @@ const char kOverlayScrollbarsOSSettingsDescription[] =
     "Enable the OS settings for overlay scrollbars on ChromeOS.";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kSupervisedProfileHideGuestName[] = "Supervised Profile Hide Guest";
 const char kSupervisedProfileHideGuestDescription[] =
     "Hides Guest Profile entry points for supervised users";
