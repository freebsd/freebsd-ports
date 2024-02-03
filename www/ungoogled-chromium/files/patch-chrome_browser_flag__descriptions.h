--- chrome/browser/flag_descriptions.h.orig	2024-02-03 15:42:55 UTC
+++ chrome/browser/flag_descriptions.h
@@ -4260,7 +4260,7 @@ extern const char kLacrosMergeIcuDataFileName[];
 extern const char kLacrosMergeIcuDataFileDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4400,14 +4400,14 @@ extern const char kSearchWebInSidePanelDescription[];
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
@@ -4417,7 +4417,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4427,7 +4427,7 @@ extern const char kOzonePlatformHintName[];
 extern const char kOzonePlatformHintDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -4435,13 +4435,13 @@ extern const char kForcePasswordInitialSyncWhenDecrypt
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
@@ -4452,7 +4452,7 @@ extern const char kEnableProtoApiForClassifyUrlName[];
 extern const char kEnableProtoApiForClassifyUrlDescription[];
 #endif  // BUILDFLAG(ENABLE_SUPERVISED_USERS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4534,7 +4534,7 @@ extern const char kElementCaptureDescription[];
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 
@@ -4570,7 +4570,7 @@ extern const char kComposeName[];
 extern const char kComposeDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
