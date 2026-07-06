--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -114,7 +114,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnExtensionURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
