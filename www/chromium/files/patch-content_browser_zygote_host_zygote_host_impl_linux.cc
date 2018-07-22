--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2018-07-19 11:56:14.006818000 +0200
+++ content/browser/zygote_host/zygote_host_impl_linux.cc	2018-07-19 11:58:05.834024000 +0200
@@ -72,6 +72,7 @@
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (command_line.HasSwitch(switches::kNoSandbox)) {
     return;
   }
@@ -130,6 +131,7 @@
            "you can try using --"
         << switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -154,6 +156,7 @@
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !defined(OS_BSD)
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -218,9 +221,12 @@
 
   AddZygotePid(pid);
   return pid;
+#else
+  return 0;
+#endif
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
