--- chrome/browser/flag_descriptions.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -5314,7 +5314,7 @@ const char kDownloadShelfWebUIDescription[] =
 // Random platform combinations -----------------------------------------------
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 const char kWebUIBrandingUpdateName[] = "WebUI Branding Update";
 const char kWebUIBrandingUpdateDescription[] =
@@ -5329,7 +5329,7 @@ const char kWebuiFeedbackDescription[] =
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 
 const char kCommanderName[] = "Commander";
 const char kCommanderDescription[] =
@@ -5348,7 +5348,7 @@ const char kDesktopDetailedLanguageSettingsDescription
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
         // defined(OS_FUCHSIA)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
 const char kDynamicTcmallocName[] = "Dynamic Tcmalloc Tuning";
 const char kDynamicTcmallocDescription[] =
@@ -5364,7 +5364,7 @@ const char kWebShareDescription[] =
     "platforms.";
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_MAC)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -5482,7 +5482,7 @@ const char kElasticOverscrollDescription[] =
 #endif  // defined(OS_WIN) || defined(OS_ANDROID)
 
 #if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
