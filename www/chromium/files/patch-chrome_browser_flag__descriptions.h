--- chrome/browser/flag_descriptions.h.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/flag_descriptions.h
@@ -299,7 +299,7 @@ extern const char kImageDescriptionsAlternateRoutingNa
 extern const char kImageDescriptionsAlternateRoutingDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionDesktopName[];
 extern const char kAutofillEnableAmountExtractionDesktopDescription[];
 #endif
@@ -694,7 +694,7 @@ extern const char kDevicePostureName[];
 extern const char kDevicePostureDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -1805,7 +1805,7 @@ extern const char kCbdTimeframeRequiredName[];
 extern const char kCbdTimeframeRequiredDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 extern const char kPolicyIndicationForManagedDefaultSearchName[];
 extern const char kPolicyIndicationForManagedDefaultSearchDescription[];
 #endif
@@ -2003,7 +2003,7 @@ extern const char kShowAutofillTypePredictionsName[];
 extern const char kShowAutofillTypePredictionsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kShowFeaturedEnterpriseSiteSearchName[];
 extern const char kShowFeaturedEnterpriseSiteSearchDescription[];
 
@@ -2025,7 +2025,7 @@ extern const char kSiteInstanceGroupsForDataUrlsName[]
 extern const char kSiteInstanceGroupsForDataUrlsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kSiteSearchSettingsPolicyName[];
 extern const char kSiteSearchSettingsPolicyDescription[];
 
@@ -4604,7 +4604,7 @@ extern const char kLacrosMergeIcuDataFileName[];
 extern const char kLacrosMergeIcuDataFileDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4750,7 +4750,7 @@ extern const char kV4L2FlatStatefulVideoDecoderDescrip
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4772,6 +4772,9 @@ extern const char kWaylandPerWindowScalingDescription[
 
 extern const char kWaylandTextInputV3Name[];
 extern const char kWaylandTextInputV3Description[];
+
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // All views-based platforms --------------------------------------------------
@@ -4801,7 +4804,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -4820,13 +4823,13 @@ extern const char kScreenlockReauthPromoCardDescriptio
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         //  BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4925,7 +4928,7 @@ extern const char kElementCaptureDescription[];
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4979,7 +4982,7 @@ extern const char kAutofillCaretExtractionName[];
 extern const char kAutofillCaretExtractionDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
@@ -5035,7 +5038,7 @@ extern const char kEnableCertManagementV2UIName[];
 extern const char kEnableCertManagementV2UIDescription[];
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedProfileHideGuestName[];
 extern const char kSupervisedProfileHideGuestDescription[];
 
