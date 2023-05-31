--- chrome/browser/flag_descriptions.h.orig	2023-05-31 08:12:17 UTC
+++ chrome/browser/flag_descriptions.h
@@ -1379,7 +1379,7 @@ extern const char kOmniboxUpdatedConnectionSecurityInd
 extern const char kWebUIOmniboxPopupName[];
 extern const char kWebUIOmniboxPopupDescription[];
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 extern const char kWebUiSystemFontName[];
 extern const char kWebUiSystemFontDescription[];
 #endif
@@ -3815,7 +3815,7 @@ extern const char kLacrosScreenCoordinatesEnabledName[
 extern const char kLacrosScreenCoordinatesEnabledDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -3942,14 +3942,14 @@ extern const char kSearchWebInSidePanelDescription[];
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
@@ -3959,7 +3959,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -3969,7 +3969,7 @@ extern const char kOzonePlatformHintName[];
 extern const char kOzonePlatformHintDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -3977,13 +3977,13 @@ extern const char kForcePasswordInitialSyncWhenDecrypt
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
@@ -3999,7 +3999,7 @@ extern const char kEnableProtoApiForClassifyUrlName[];
 extern const char kEnableProtoApiForClassifyUrlDescription[];
 #endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kUseOutOfProcessVideoDecodingName[];
 extern const char kUseOutOfProcessVideoDecodingDescription[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -4073,7 +4073,7 @@ extern const char kElasticOverscrollDescription[];
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 
@@ -4091,7 +4091,7 @@ extern const char kSigninInterceptBubbleV2Description[
 #endif
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kDataRetentionPoliciesDisableSyncTypesNeededName[];
 extern const char kDataRetentionPoliciesDisableSyncTypesNeededDescription[];
 #endif
