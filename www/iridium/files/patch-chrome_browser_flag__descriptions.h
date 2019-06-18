--- chrome/browser/flag_descriptions.h.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/flag_descriptions.h
@@ -2192,12 +2192,12 @@ extern const char kWakeOnPacketsDescription[];
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kEnableInputImeApiName[];
 extern const char kEnableInputImeApiDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kExperimentalUiName[];
 extern const char kExperimentalUiDescription[];
@@ -2209,12 +2209,12 @@ extern const char kAutomaticTabDiscardingDescription[]
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
