--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -121,7 +121,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kAllowlistedExtensionID,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/40078530
     switches::kEnableSpeechDispatcher,
