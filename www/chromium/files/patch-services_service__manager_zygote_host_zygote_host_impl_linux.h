--- services/service_manager/zygote/host/zygote_host_impl_linux.h.orig	2018-08-04 19:08:46.425404000 +0200
+++ services/service_manager/zygote/host/zygote_host_impl_linux.h	2018-08-04 19:09:48.783775000 +0200
@@ -44,8 +44,10 @@
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
 
  private:
   friend struct base::DefaultSingletonTraits<ZygoteHostImpl>;
