--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2026-10-18 13:29:39 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -21,8 +21,10 @@
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
@@ -40,6 +42,7 @@ namespace content {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Receive a fixed message on fd and return the sender's PID.
 // Returns true if the message received matches the expected message.
 bool ReceiveFixedMessage(int fd,
@@ -62,6 +65,7 @@ bool ReceiveFixedMessage(int fd,
     return false;
   return true;
 }
+#endif
 
 }  // namespace
 
@@ -71,9 +75,13 @@ ZygoteHost* ZygoteHost::GetInstance() {
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
@@ -86,6 +94,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !BUILDFLAG(IS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -140,6 +149,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -164,6 +174,7 @@ ZygoteLaunchCompletionCallback ZygoteHostImpl::LaunchZ
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !BUILDFLAG(IS_BSD)
   has_zygote_ = true;
 
   int fds[2];
@@ -209,10 +220,15 @@ ZygoteLaunchCompletionCallback ZygoteHostImpl::LaunchZ
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
@@ -263,9 +279,12 @@ pid_t ZygoteHostImpl::FinishSandboxedZygoteLaunch(base
 
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
