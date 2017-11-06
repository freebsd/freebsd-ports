--- content/public/browser/zygote_host_linux.h.orig	2017-09-07 23:29:05.803550000 +0200
+++ content/public/browser/zygote_host_linux.h	2017-09-07 23:29:43.081801000 +0200
@@ -30,11 +30,13 @@
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() const = 0;
 
+#if !defined(OS_FREEBSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace content
