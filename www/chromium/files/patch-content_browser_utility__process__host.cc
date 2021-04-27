--- content/browser/utility_process_host.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/utility_process_host.cc
@@ -62,7 +62,7 @@ UtilityProcessHost::UtilityProcessHost()
 
 UtilityProcessHost::UtilityProcessHost(std::unique_ptr<Client> client)
     : sandbox_type_(sandbox::policy::SandboxType::kUtility),
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -231,8 +231,8 @@ bool UtilityProcessHost::StartProcess() {
       sandbox::policy::switches::kNoSandbox,
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-    !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS))
       switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_MAC)
