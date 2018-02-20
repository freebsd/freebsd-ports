--- content/utility/utility_main.cc.orig	2018-01-20 16:08:49.686959000 +0100
+++ content/utility/utility_main.cc	2018-01-20 16:09:13.242607000 +0100
@@ -45,7 +45,7 @@
   if (parameters.command_line.HasSwitch(switches::kUtilityStartupDialog))
     WaitForDebugger("Utility");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
