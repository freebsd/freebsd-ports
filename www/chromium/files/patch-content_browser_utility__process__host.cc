--- content/browser/utility_process_host.cc.orig	2020-09-08 19:14:05 UTC
+++ content/browser/utility_process_host.cc
@@ -275,7 +275,7 @@ UtilityProcessHost::UtilityProcessHost()
 
 UtilityProcessHost::UtilityProcessHost(std::unique_ptr<Client> client)
     : sandbox_type_(service_manager::SandboxType::kUtility),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -446,7 +446,7 @@ bool UtilityProcessHost::StartProcess() {
       network::switches::kNetLogCaptureMode,
       network::switches::kExplicitlyAllowedPorts,
       service_manager::switches::kNoSandbox,
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       switches::kDisableDevShmUsage,
 #endif
       service_manager::switches::kEnableAudioServiceSandbox,
