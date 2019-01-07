--- chrome/browser/flag_descriptions.cc.orig	2018-12-12 22:56:03.000000000 +0100
+++ chrome/browser/flag_descriptions.cc	2018-12-28 16:55:56.434650000 +0100
@@ -3555,13 +3555,13 @@
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 const char kEnableInputImeApiDescription[] =
     "Enable the use of chrome.input.ime API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MACOSX)
 
@@ -3574,13 +3574,13 @@
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kExperimentalUiName[] = "Use all upcoming UI features";
 const char kExperimentalUiDescription[] = "Use all upcoming UI features.";
