--- content/browser/utility_process_host.cc.orig	2019-05-04 09:00:43 UTC
+++ content/browser/utility_process_host.cc
@@ -209,7 +209,7 @@ UtilityProcessHost::UtilityProcessHost(
     : client_(client),
       client_task_runner_(client_task_runner),
       sandbox_type_(service_manager::SANDBOX_TYPE_UTILITY),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
