--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -93,7 +93,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnChromeURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
