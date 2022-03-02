--- chrome/browser/flag_descriptions.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -5323,7 +5323,7 @@ const char kDownloadShelfWebUIDescription[] =
 // Random platform combinations -----------------------------------------------
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 const char kWebUIBrandingUpdateName[] = "WebUI Branding Update";
 const char kWebUIBrandingUpdateDescription[] =
@@ -5338,7 +5338,7 @@ const char kWebuiFeedbackDescription[] =
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 const char kCommanderName[] = "Commander";
 const char kCommanderDescription[] =
@@ -5357,7 +5357,7 @@ const char kDesktopDetailedLanguageSettingsDescription
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kImproveAccessibilityTreeUsingLocalMLName[] =
     "Enable improving accessibility tree using local machine learning library.";
 const char kImproveAccessibilityTreeUsingLocalMLDescription[] =
@@ -5372,7 +5372,7 @@ const char kWebShareDescription[] =
     "platforms.";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -5384,7 +5384,7 @@ const char kOzonePlatformHintDescription[] =
     "\"X11\". \"Auto\" selects Wayland if possible, X11 otherwise. ";
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kCleanUndecryptablePasswordsLinuxName[] =
     "Cleanup local undecryptable passwords during initial sync flow";
 const char kCleanUndecryptablePasswordsLinuxDescription[] =
@@ -5500,7 +5500,7 @@ const char kElasticOverscrollDescription[] =
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
