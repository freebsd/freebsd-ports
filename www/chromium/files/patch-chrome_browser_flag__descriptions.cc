--- chrome/browser/flag_descriptions.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -1598,14 +1598,14 @@ const char kForceUiDirectionLtr[] = "Left-to-right";
 
 const char kForceUiDirectionRtl[] = "Right-to-left";
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 
 const char kEnableInputImeApiDescription[] =
     "Enable the use of chrome.input.ime API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableGroupedHistoryName[] = "Group history by domain";
 
