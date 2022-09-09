--- chrome/browser/flag_descriptions.h.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/flag_descriptions.h
@@ -3477,7 +3477,7 @@ extern const char kSideSearchDSESupportDescription[];
 // Random platform combinations -----------------------------------------------
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 extern const char kDesktopDetailedLanguageSettingsName[];
 extern const char kDesktopDetailedLanguageSettingsDescription[];
@@ -3498,7 +3498,7 @@ extern const char kWebBluetoothConfirmPairingSupportNa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -3514,12 +3514,12 @@ extern const char kForcePasswordInitialSyncWhenDecrypt
 extern const char kForcePasswordInitialSyncWhenDecryptionFailsDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kAsyncDnsName[];
 extern const char kAsyncDnsDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -3595,7 +3595,7 @@ extern const char kElasticOverscrollDescription[];
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
