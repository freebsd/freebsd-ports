--- chrome/browser/chrome_browser_main.cc.orig	2012-05-19 23:45:48.797106216 +0300
+++ chrome/browser/chrome_browser_main.cc	2012-05-19 23:45:56.878106198 +0300
@@ -1298,7 +1298,7 @@
   // just changed it to include experiments.
   child_process_logging::SetCommandLine(CommandLine::ForCurrentProcess());
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   child_process_logging::SetChannel(
       chrome::VersionInfo::GetVersionStringModifier());
