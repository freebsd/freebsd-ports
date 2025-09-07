--- content/child/child_process.cc.orig	2025-09-06 10:01:20 UTC
+++ content/child/child_process.cc
@@ -34,7 +34,7 @@
 #include "content/common/android/cpu_time_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -192,7 +192,7 @@ void ChildProcess::set_main_thread(ChildThreadImpl* th
   main_thread_.reset(thread);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChildProcess::SetIOThreadType(base::ThreadType thread_type) {
   if (!io_thread_) {
     return;
