--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2021-04-14 18:40:55 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -96,7 +96,7 @@ static const char* kBadFlags[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
