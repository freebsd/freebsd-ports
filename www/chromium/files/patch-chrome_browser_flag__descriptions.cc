--- chrome/browser/flag_descriptions.cc.orig	2019-04-30 22:22:33 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -3524,21 +3524,21 @@ extern const char kAshNotificationStackingBarRedesignD
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 const char kEnableInputImeApiDescription[] =
     "Enable the use of chrome.input.ime API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
     "Enable the use of WebGL 2.0 Compute API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MACOSX)
 
@@ -3551,13 +3551,13 @@ const char kAutomaticTabDiscardingDescription[] =
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
