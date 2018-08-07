--- services/service_manager/zygote/zygote_host_linux.h.orig	2018-08-04 19:14:58.401790000 +0200
+++ services/service_manager/zygote/zygote_host_linux.h	2018-08-04 19:15:49.368693000 +0200
@@ -30,11 +30,13 @@
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() const = 0;
 
+#if !defined(OS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace service_manager
