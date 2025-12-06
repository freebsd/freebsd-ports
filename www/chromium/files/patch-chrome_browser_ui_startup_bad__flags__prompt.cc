--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -111,7 +111,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnExtensionURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
