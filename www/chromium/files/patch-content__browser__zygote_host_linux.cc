--- content/browser/zygote_host_linux.cc.orig	2012-01-18 11:11:40.000000000 +0200
+++ content/browser/zygote_host_linux.cc	2012-01-29 16:31:59.000000000 +0200
@@ -305,7 +305,7 @@
       return base::kNullProcessHandle;
   }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
   // This is just a starting score for a renderer or extension (the
   // only types of processes that will be started this way).  It will
   // get adjusted as time goes on.  (This is the same value as
@@ -318,7 +318,7 @@
   return pid;
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHost::AdjustRendererOOMScore(base::ProcessHandle pid, int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
   //    (EPERM) unless you're root. Because of this, we can't set the
