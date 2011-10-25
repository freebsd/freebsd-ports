--- content/browser/zygote_host_linux.cc.orig	2011-10-07 11:31:44.000000000 +0300
+++ content/browser/zygote_host_linux.cc	2011-10-08 22:10:14.930730097 +0300
@@ -271,6 +271,7 @@
       return base::kNullProcessHandle;
   }
 
+#if !defined(OS_FREEBSD)
   // This is just a starting score for a renderer or extension (the
   // only types of processes that will be started this way).  It will
   // get adjusted as time goes on.  (This is the same value as
@@ -278,6 +279,7 @@
   // that's not something we can include here.)
   const int kLowestRendererOomScore = 300;
   AdjustRendererOOMScore(pid, kLowestRendererOomScore);
+#endif
 
   return pid;
 }
