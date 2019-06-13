--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -88,7 +88,7 @@ static const char* kBadFlags[] = {
     extensions::switches::kExtensionsOnChromeURLs,
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
