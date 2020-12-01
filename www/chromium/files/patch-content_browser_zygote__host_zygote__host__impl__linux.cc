--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2020-11-18 15:42:24 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -73,6 +73,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
     return;
   }
@@ -123,6 +124,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << sandbox::policy::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -147,6 +149,9 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+#else
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -214,9 +219,10 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
   AddZygotePid(pid);
   return pid;
+#endif
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
