--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2012-05-09 10:01:22.000000000 +0300
+++ content/browser/zygote_host/zygote_host_impl_linux.cc	2012-05-20 02:32:55.863105935 +0300
@@ -92,7 +92,7 @@
   cmd_line.AppendSwitchASCII(switches::kProcessType, switches::kZygoteProcess);
 
   int fds[2];
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#if defined(OS_BSD)
   // The BSDs often don't support SOCK_SEQPACKET yet, so fall back to
   // SOCK_DGRAM if necessary.
   if (socketpair(PF_UNIX, SOCK_SEQPACKET, 0, fds) != 0)
@@ -310,7 +310,7 @@
       return base::kNullProcessHandle;
   }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
   // This is just a starting score for a renderer or extension (the
   // only types of processes that will be started this way).  It will
   // get adjusted as time goes on.  (This is the same value as
@@ -323,9 +323,9 @@
   return pid;
 }
 
-#if !defined(OS_OPENBSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
+#if !defined(OS_BSD)
   // 1) You can't change the oom_score_adj of a non-dumpable process
   //    (EPERM) unless you're root. Because of this, we can't set the
   //    oom_adj from the browser process.
@@ -390,8 +390,9 @@
     if (!base::AdjustOOMScore(pid, score))
       PLOG(ERROR) << "Failed to adjust OOM score of renderer with pid " << pid;
   }
-}
 #endif
+}
+
 
 void ZygoteHostImpl::EnsureProcessTerminated(pid_t process) {
   DCHECK(init_);
