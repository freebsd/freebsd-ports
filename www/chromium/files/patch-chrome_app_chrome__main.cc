--- chrome/app/chrome_main.cc.orig	2018-12-03 21:16:35.000000000 +0100
+++ chrome/app/chrome_main.cc	2018-12-05 14:12:24.772160000 +0100
@@ -93,11 +93,11 @@
 #endif
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
   int rv = content::ContentMain(params);
 
