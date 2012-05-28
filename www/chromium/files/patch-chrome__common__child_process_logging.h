--- chrome/common/child_process_logging.h.orig	2012-04-25 10:02:56.000000000 +0300
+++ chrome/common/child_process_logging.h	2012-04-29 20:33:00.000000000 +0300
@@ -98,7 +98,7 @@
 // values in |command_line|.
 void SetCommandLine(const CommandLine* command_line);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
 // Sets the product channel data to send along with crash reports to |channel|.
 void SetChannel(const std::string& channel);
 #endif
