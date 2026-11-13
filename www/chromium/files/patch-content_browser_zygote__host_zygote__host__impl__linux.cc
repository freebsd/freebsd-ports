--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2026-11-11 14:44:17 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -24,8 +24,10 @@
 #include "build/build_config.h"
 #include "content/common/zygote/zygote_commands_linux.h"
 #include "content/common/zygote/zygote_communication_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/common/zygote/zygote_handle_impl_linux.h"
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/linux/services/credentials.h"
 #include "sandbox/linux/services/namespace_sandbox.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_host.h"
@@ -43,6 +45,7 @@ namespace content {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Receive a fixed message on fd and return the sender's PID.
 // Returns true if the message received matches the expected message.
 bool ReceiveFixedMessage(int fd,
@@ -65,6 +68,7 @@ bool ReceiveFixedMessage(int fd,
     return false;
   return true;
 }
+#endif
 
 // Returns a description of the sandbox a zygote that exited prematurely with
 // |exit_code| was launched in and, if the setuid sandbox helper failed to set
@@ -85,9 +89,13 @@ ZygoteHost* ZygoteHost::GetInstance() {
 }
 
 ZygoteHostImpl::ZygoteHostImpl()
+#if !BUILDFLAG(IS_BSD)
     : use_namespace_sandbox_(false),
       use_suid_sandbox_(false),
       use_suid_sandbox_for_adj_oom_score_(false),
+#else
+    :
+#endif
       sandbox_binary_(),
       zygote_pids_lock_(),
       zygote_pids_() {}
@@ -100,6 +108,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !BUILDFLAG(IS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -154,6 +163,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -178,6 +188,7 @@ ZygoteLaunchCompletionCallback ZygoteHostImpl::LaunchZ
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !BUILDFLAG(IS_BSD)
   has_zygote_ = true;
 
   int fds[2];
@@ -223,10 +234,15 @@ ZygoteLaunchCompletionCallback ZygoteHostImpl::LaunchZ
   const pid_t pid = process.Pid();
   AddZygotePid(pid);
   return base::BindOnce([](pid_t pid) { return pid; }, pid);
+#else
+  const pid_t pid = getpid();
+  return base::BindOnce([](pid_t pid) { return pid; }, pid);
+#endif
 }
 
 pid_t ZygoteHostImpl::FinishSandboxedZygoteLaunch(base::Process process,
                                                   int control_fd) {
+#if !BUILDFLAG(IS_BSD)
   // The namespace and SUID sandbox will execute the zygote in a new
   // PID namespace, and the main zygote process will then fork from
   // there. Watch now our elaborate dance to find and validate the
@@ -281,9 +297,12 @@ pid_t ZygoteHostImpl::FinishSandboxedZygoteLaunch(base
 
   AddZygotePid(real_pid);
   return real_pid;
+#else
+  return getpid();
+#endif
 }
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
