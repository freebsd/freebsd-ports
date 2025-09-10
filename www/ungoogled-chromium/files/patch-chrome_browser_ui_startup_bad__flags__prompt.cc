--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -104,7 +104,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnExtensionURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
