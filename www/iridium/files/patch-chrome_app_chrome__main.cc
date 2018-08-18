--- chrome/app/chrome_main.cc.orig	2017-09-05 21:05:12.000000000 +0200
+++ chrome/app/chrome_main.cc	2017-09-06 17:23:42.720920000 +0200
@@ -99,14 +99,14 @@
   ALLOW_UNUSED_LOCAL(command_line);
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
 #if defined(OS_MACOSX)
     SetUpBundleOverrides();
 #endif
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_OOP_HEAP_PROFILING)
 #if !defined(OS_WIN) || defined(COMPONENT_BUILD) || \
