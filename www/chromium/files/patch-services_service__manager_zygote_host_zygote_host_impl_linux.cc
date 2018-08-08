--- services/service_manager/zygote/host/zygote_host_impl_linux.cc.orig	2018-08-04 19:08:22.136631000 +0200
+++ services/service_manager/zygote/host/zygote_host_impl_linux.cc	2018-08-04 19:11:54.463784000 +0200
@@ -72,6 +72,7 @@
 }
 
 void ZygoteHostImpl::Init(const base::CommandLine& command_line) {
+#if !defined(OS_BSD)
   if (command_line.HasSwitch(service_manager::switches::kNoSandbox)) {
     return;
   }
@@ -133,6 +134,7 @@
            "you can try using --"
         << service_manager::switches::kNoSandbox << ".";
   }
+#endif
 }
 
 void ZygoteHostImpl::AddZygotePid(pid_t pid) {
@@ -157,6 +159,7 @@
     base::CommandLine* cmd_line,
     base::ScopedFD* control_fd,
     base::FileHandleMappingVector additional_remapped_fds) {
+#if !defined(OS_BSD)
   int fds[2];
   CHECK_EQ(0, socketpair(AF_UNIX, SOCK_SEQPACKET, 0, fds));
   CHECK(base::UnixDomainSocket::EnableReceiveProcessId(fds[0]));
@@ -221,9 +224,12 @@
 
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
