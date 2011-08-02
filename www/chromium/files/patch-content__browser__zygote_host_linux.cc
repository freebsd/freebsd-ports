--- content/browser/zygote_host_linux.cc.orig	2011-06-24 11:30:33.000000000 +0300
+++ content/browser/zygote_host_linux.cc	2011-06-26 21:23:29.109780851 +0300
@@ -61,8 +61,16 @@
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
@@ -160,6 +168,7 @@
     // We need to look for it.
     // But first, wait for the zygote to tell us it's running.
     // The sending code is in chrome/browser/zygote_main_linux.cc.
+#if defined(OS_LINUX)
     std::vector<int> fds_vec;
     const int kExpectedLength = sizeof(kZygoteMagic);
     char buf[kExpectedLength];
@@ -190,6 +199,7 @@
       // Reap the sandbox.
       ProcessWatcher::EnsureProcessGetsReaped(process);
     }
+#endif // defined(OS_LINUX)
   } else {
     // Not using the SUID sandbox.
     pid_ = process;
@@ -256,9 +266,11 @@
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
@@ -296,6 +308,7 @@
     selinux_valid = true;
   }
 
+#if defined(OS_LINUX)
   if (using_suid_sandbox_ && !selinux) {
     base::ProcessHandle sandbox_helper_process;
     std::vector<std::string> adj_oom_score_cmdline;
@@ -313,6 +326,7 @@
     if (!base::AdjustOOMScore(pid, score))
       PLOG(ERROR) << "Failed to adjust OOM score of renderer with pid " << pid;
   }
+#endif // defined(OS_LINUX)
 }
 
 void ZygoteHost::EnsureProcessTerminated(pid_t process) {
