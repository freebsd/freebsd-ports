--- services/service_manager/zygote/host/zygote_host_impl_linux.h.orig	2019-01-30 02:18:10.000000000 +0100
+++ services/service_manager/zygote/host/zygote_host_impl_linux.h	2019-02-01 10:48:51.105096000 +0100
@@ -44,8 +44,10 @@
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
   bool HasZygote() { return !zygote_pids_.empty(); }
 
  private:
