--- chrome/app/chrome_main.cc.orig	2017-07-25 21:04:49.000000000 +0200
+++ chrome/app/chrome_main.cc	2017-08-01 23:35:54.553290000 +0200
@@ -92,7 +92,7 @@
   const base::CommandLine* command_line(base::CommandLine::ForCurrentProcess());
   ALLOW_UNUSED_LOCAL(command_line);
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
 #if defined(OS_MACOSX)
     SetUpBundleOverrides();
