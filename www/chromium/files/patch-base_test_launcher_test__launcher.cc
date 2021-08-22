--- base/test/launcher/test_launcher.cc.orig	2021-07-19 18:45:05 UTC
+++ base/test/launcher/test_launcher.cc
@@ -60,6 +60,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
@@ -601,7 +602,7 @@ ChildProcessResults DoLaunchChildTestProcess(
 #if !defined(OS_FUCHSIA)
   options.new_process_group = true;
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   options.kill_on_parent_death = true;
 #endif
 
@@ -1523,7 +1524,7 @@ bool TestLauncher::Init(CommandLine* command_line) {
   results_tracker_.AddGlobalTag("OS_IOS");
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   results_tracker_.AddGlobalTag("OS_LINUX");
 #endif
 
