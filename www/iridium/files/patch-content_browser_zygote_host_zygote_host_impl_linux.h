--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2018-08-16 15:34:11.475341000 +0200
+++ content/browser/zygote_host/zygote_host_impl_linux.h	2018-08-16 15:36:05.256933000 +0200
@@ -41,8 +41,10 @@
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
 
  private:
   friend struct base::DefaultSingletonTraits<ZygoteHostImpl>;
