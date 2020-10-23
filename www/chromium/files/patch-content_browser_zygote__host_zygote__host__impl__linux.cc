--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2020-09-16 15:03:02 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -73,6 +73,7 @@ ZygoteHostImpl* ZygoteHostImpl::GetInstance() {
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)        
   if (command_line.HasSwitch(service_manager::switches::kNoSandbox)) {
     return;
   }
@@ -123,6 +124,7 @@ void ZygoteHostImpl::Init(const base::CommandLine& com
            "you can try using --"
         << service_manager::switches::kNoSandbox << ".";
   }
+#endif // !defined(OS_BSD)
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -148,6 +150,7 @@ pid_t ZygoteHostImpl::LaunchZygote(
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
   int fds[2];
+#if !defined(OS_BSD)  
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
 
@@ -214,9 +217,12 @@ pid_t ZygoteHostImpl::LaunchZygote(
 
   AddZygotePid(pid);
   return pid;
+#else
+  return 0;
+#endif // !defined(OS_BSD)
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
