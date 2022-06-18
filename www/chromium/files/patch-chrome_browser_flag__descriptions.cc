--- chrome/browser/flag_descriptions.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -5709,7 +5709,7 @@ const char kSideSearchDSESupportDescription[] =
 // Random platform combinations -----------------------------------------------
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 const char kDesktopRestructuredLanguageSettingsName[] =
     "Restructured Language Settings (Desktop)";
@@ -5735,7 +5735,7 @@ const char kWebShareDescription[] =
     "platforms.";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -5747,7 +5747,7 @@ const char kOzonePlatformHintDescription[] =
     "\"X11\". \"Auto\" selects Wayland if possible, X11 otherwise. ";
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kCleanUndecryptablePasswordsLinuxName[] =
     "Cleanup local undecryptable passwords during initial sync flow";
 const char kCleanUndecryptablePasswordsLinuxDescription[] =
@@ -5760,7 +5760,7 @@ const char kForcePasswordInitialSyncWhenDecryptionFail
     "storage and requests initial sync.";
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kSkipUndecryptablePasswordsName[] =
     "Skip undecryptable passwords to use the available decryptable "
     "passwords.";
@@ -5875,7 +5875,7 @@ const char kElasticOverscrollDescription[] =
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
