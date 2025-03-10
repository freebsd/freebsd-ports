--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -94,7 +94,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnChromeURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
