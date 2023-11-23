--- chrome/browser/flag_descriptions.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/flag_descriptions.h
@@ -1485,7 +1485,7 @@ extern const char kOmnibox2023RefreshConnectionSecurit
 extern const char kWebUIOmniboxPopupName[];
 extern const char kWebUIOmniboxPopupDescription[];
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 extern const char kWebUiSystemFontName[];
 extern const char kWebUiSystemFontDescription[];
 #endif
@@ -4172,7 +4172,7 @@ extern const char kLacrosMergeIcuDataFileName[];
 extern const char kLacrosMergeIcuDataFileDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4302,14 +4302,14 @@ extern const char kSearchWebInSidePanelDescription[];
 // Random platform combinations -----------------------------------------------
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kQuickCommandsName[];
 extern const char kQuickCommandsDescription[];
 
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // defined (OS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kWebShareName[];
 extern const char kWebShareDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
@@ -4319,7 +4319,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4329,7 +4329,7 @@ extern const char kOzonePlatformHintName[];
 extern const char kOzonePlatformHintDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -4337,13 +4337,13 @@ extern const char kForcePasswordInitialSyncWhenDecrypt
 extern const char kForcePasswordInitialSyncWhenDecryptionFailsDescription[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kAsyncDnsName[];
 extern const char kAsyncDnsDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -4354,7 +4354,7 @@ extern const char kEnableProtoApiForClassifyUrlName[];
 extern const char kEnableProtoApiForClassifyUrlDescription[];
 #endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4431,7 +4431,7 @@ extern const char kElasticOverscrollDescription[];
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 
@@ -4440,7 +4440,7 @@ extern const char kSyncPollImmediatelyOnEveryStartupDe
 #endif
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kDataRetentionPoliciesDisableSyncTypesNeededName[];
 extern const char kDataRetentionPoliciesDisableSyncTypesNeededDescription[];
 #endif
@@ -4467,7 +4467,7 @@ extern const char kEnableAudioFocusEnforcementName[];
 extern const char kEnableAudioFocusEnforcementDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
