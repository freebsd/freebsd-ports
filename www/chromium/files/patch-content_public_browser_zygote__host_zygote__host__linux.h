--- content/public/browser/zygote_host/zygote_host_linux.h.orig	2021-04-14 18:41:03 UTC
+++ content/public/browser/zygote_host/zygote_host_linux.h
@@ -30,11 +30,13 @@ class ZygoteHost {
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() = 0;
 
+#if !defined(OS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace content
