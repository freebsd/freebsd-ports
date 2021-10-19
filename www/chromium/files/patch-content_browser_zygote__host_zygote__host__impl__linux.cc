--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2021-10-01 01:36:48 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -26,6 +26,7 @@
 
 namespace content {
 
+#if !defined(OS_BSD)
 namespace {
 
 // Receive a fixed message on fd and return the sender's PID.
@@ -51,6 +52,7 @@ bool ReceiveFixedMessage(int fd,
 }
 
 }  // namespace
+#endif
 
 // static
 ZygoteHost* ZygoteHost::GetInstance() {
@@ -58,10 +60,14 @@ ZygoteHost* ZygoteHost::GetInstance() {
 }
 
 ZygoteHostImpl::ZygoteHostImpl()
+#if !defined(OS_BSD)
     : use_namespace_sandbox_(false),
       use_suid_sandbox_(false),
       use_suid_sandbox_for_adj_oom_score_(false),
       sandbox_binary_(),
+#else
+    : sandbox_binary_(),
+#endif
       zygote_pids_lock_(),
       zygote_pids_() {}
 
@@ -73,6 +79,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -123,6 +130,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -147,6 +155,10 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return -1;
+#else
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -214,9 +226,10 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
   AddZygotePid(pid);
   return pid;
+#endif
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
