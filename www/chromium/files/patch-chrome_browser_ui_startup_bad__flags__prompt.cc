--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -120,7 +120,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kAllowlistedExtensionID,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
