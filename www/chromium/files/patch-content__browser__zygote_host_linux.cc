--- content/browser/zygote_host_linux.cc.orig	2011-04-16 11:01:10.000000000 +0300
+++ content/browser/zygote_host_linux.cc	2011-04-27 00:55:54.430982567 +0300
@@ -8,6 +8,9 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#if defined(OS_FREEBSD)
+#include <sys/param.h>
+#endif
 
 #include "base/command_line.h"
 #include "base/eintr_wrapper.h"
@@ -61,8 +64,16 @@
 }
 
 ZygoteHost::~ZygoteHost() {
-  if (init_)
+#if defined(OS_FREEBSD)
+  Pickle pickle;
+#endif
+  if (init_) {
+#if defined(OS_FREEBSD)
+    pickle.WriteInt(kCmdEnd);
+    HANDLE_EINTR(write(control_fd_, pickle.data(), pickle.size()));
+#endif
     close(control_fd_);
+  }
 }
 
 // static
@@ -81,7 +92,11 @@
   cmd_line.AppendSwitchASCII(switches::kProcessType, switches::kZygoteProcess);
 
   int fds[2];
+#if defined(OS_FREEBSD) && (__FreeBSD_version < 900030)
+  CHECK(socketpair(AF_UNIX, SOCK_DGRAM, 0, fds) == 0);
+#else
   CHECK(socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) == 0);
+#endif
   base::file_handle_mapping_vector fds_to_map;
   fds_to_map.push_back(std::make_pair(fds[1], 3));
 
@@ -149,6 +164,7 @@
     // We need to look for it.
     // But first, wait for the zygote to tell us it's running.
     // The sending code is in chrome/browser/zygote_main_linux.cc.
+#if defined(OS_LINUX)
     std::vector<int> fds_vec;
     const int kExpectedLength = sizeof(kZygoteMagic);
     char buf[kExpectedLength];
@@ -179,6 +195,7 @@
       // Reap the sandbox.
       ProcessWatcher::EnsureProcessGetsReaped(process);
     }
+#endif // defined(OS_LINUX)
   } else {
     // Not using the SUID sandbox.
     pid_ = process;
@@ -245,9 +262,11 @@
     if (pid <= 0)
       return base::kNullProcessHandle;
   }
-
+  
+#if defined(OS_LINUX)
   const int kRendererScore = 5;
   AdjustRendererOOMScore(pid, kRendererScore);
+#endif
 
   return pid;
 }
@@ -285,6 +304,7 @@
     selinux_valid = true;
   }
 
+#if defined(OS_LINUX)
   if (using_suid_sandbox_ && !selinux) {
     base::ProcessHandle sandbox_helper_process;
     std::vector<std::string> adj_oom_score_cmdline;
@@ -302,6 +322,7 @@
     if (!base::AdjustOOMScore(pid, score))
       PLOG(ERROR) << "Failed to adjust OOM score of renderer with pid " << pid;
   }
+#endif // defined(OS_LINUX)
 }
 
 void ZygoteHost::EnsureProcessTerminated(pid_t process) {
