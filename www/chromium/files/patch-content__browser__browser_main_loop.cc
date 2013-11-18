--- content/browser/browser_main_loop.cc.orig	2013-02-28 10:14:31.000000000 +0200
+++ content/browser/browser_main_loop.cc	2013-03-06 21:28:00.000000000 +0200
@@ -87,7 +87,7 @@
 #include "ui/gfx/gtk_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include <sys/stat.h>
 
 #include "base/process_util.h"
@@ -111,7 +111,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const CommandLine& parsed_command_line) {
   // TODO(evanm): move this into SandboxWrapper; I'm just trying to move this
   // code en masse out of chrome_main for now.
@@ -311,7 +311,7 @@
   crypto::EnsureNSPRInit();
 #endif  // !defined(USE_OPENSSL)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   SetupSandbox(parsed_command_line_);
 #endif
 
