--- content/browser/gpu/gpu_process_host.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/gpu/gpu_process_host.cc	2016-08-18 02:45:06.533983000 +0300
@@ -968,7 +968,7 @@
   base::CommandLine* cmd_line =
       new base::CommandLine(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                            ChildProcessHost::CHILD_NORMAL;
 #else
