--- chrome/browser/ui/aura/chrome_browser_main_extra_parts_aura.cc.orig	2015-01-26 10:30:44
+++ chrome/browser/ui/aura/chrome_browser_main_extra_parts_aura.cc
@@ -128,7 +128,7 @@
 }
 
 void ChromeBrowserMainExtraPartsAura::PreProfileInit() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Now that we have some minimal ui initialized, check to see if we're
   // running as root and bail if we are.
   DetectRunningAsRoot();
@@ -142,7 +142,7 @@
   // after the metrics service is deleted.
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void ChromeBrowserMainExtraPartsAura::DetectRunningAsRoot() {
   if (getuid() == 0) {
     const CommandLine& command_line = *CommandLine::ForCurrentProcess();
