--- chrome/browser/flag_descriptions.cc.orig	2017-09-05 21:05:13.000000000 +0200
+++ chrome/browser/flag_descriptions.cc	2017-09-10 01:52:30.845374000 +0200
@@ -2155,14 +2155,14 @@
 
 #endif  // defined(TOOLKIT_VIEWS) || defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 
 const char kEnableInputImeApiDescription[] =
     "Enable the use of chrome.input.ime API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 
@@ -2414,7 +2414,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 
 const char kOmniboxEntitySuggestionsName[] = "Omnibox entity suggestions";
 const char kOmniboxEntitySuggestionsDescription[] =
