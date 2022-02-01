--- chrome/browser/flag_descriptions.cc.orig	2022-01-20 10:35:49 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -5258,7 +5258,7 @@ const char kDownloadShelfWebUIDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 const char kWebUIBrandingUpdateName[] = "WebUI Branding Update";
@@ -5276,10 +5276,10 @@ const char kSettingsLandingPageRedesignDescription[] =
     "Changes the layout of the chrome://settings page to only show one section "
     "at a time.";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kCommanderName[] = "Commander";
 const char kCommanderDescription[] =
@@ -5295,7 +5295,7 @@ const char kDesktopDetailedLanguageSettingsName[] =
 const char kDesktopDetailedLanguageSettingsDescription[] =
     "Enable the new detailed language settings page";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX)
 #if BUILDFLAG(USE_TCMALLOC)
@@ -5320,7 +5320,7 @@ const char kWebShareDescription[] =
     "platforms.";
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_MAC)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -5330,7 +5330,7 @@ const char kOzonePlatformHintName[] = "Preferred Ozone
 const char kOzonePlatformHintDescription[] =
     "Selects the preferred platform backend used on Linux. The default one is "
     "\"X11\". \"Auto\" selects Wayland if possible, X11 otherwise. ";
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 // Feature flags --------------------------------------------------------------
 
@@ -5422,7 +5422,7 @@ const char kAutofillCreditCardUploadDescription[] =
 
 #endif  // defined(TOOLKIT_VIEWS) || defined(OS_ANDROID)
 
-#if !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 const char kSendWebUIJavaScriptErrorReportsName[] =
     "Send WebUI JavaScript Error Reports";
 const char kSendWebUIJavaScriptErrorReportsDescription[] =
@@ -5437,7 +5437,7 @@ const char kElasticOverscrollDescription[] =
     "Enables Elastic Overscrolling on touchscreens and precision touchpads.";
 #endif  // defined(OS_WIN) || defined(OS_ANDROID)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
