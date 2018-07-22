--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2018-06-13 00:10:17.000000000 +0200
+++ content/browser/zygote_host/zygote_host_impl_linux.h	2018-07-19 11:55:28.795795000 +0200
@@ -41,8 +41,10 @@
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
 
  private:
   friend struct base::DefaultSingletonTraits<ZygoteHostImpl>;
