--- chrome/browser/flag_descriptions.h.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/flag_descriptions.h
@@ -1754,7 +1754,7 @@ extern const char kForceUiDirectionLtr[];
 // Name for the option to force right-to-left UI direction mode.
 extern const char kForceUiDirectionRtl[];
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Name of the flag to enable che chrome.input.ime API.
 extern const char kEnableInputImeApiName[];
@@ -1762,7 +1762,7 @@ extern const char kEnableInputImeApiName[];
 // Description of the flag to enable the chrome.input.ime API.
 extern const char kEnableInputImeApiDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Enables grouping websites by domain on chrome://history.
 extern const char kEnableGroupedHistoryName[];
