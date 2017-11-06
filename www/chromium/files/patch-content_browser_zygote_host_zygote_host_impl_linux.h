--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2017-09-07 23:31:20.865003000 +0200
+++ content/browser/zygote_host/zygote_host_impl_linux.h	2017-09-07 23:32:15.495651000 +0200
@@ -37,8 +37,10 @@
   int GetRendererSandboxStatus() const override;
 
   pid_t LaunchZygote(base::CommandLine* cmd_line, base::ScopedFD* control_fd);
+#if !defined(OS_FREEBSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
 
  private:
   friend struct base::DefaultSingletonTraits<ZygoteHostImpl>;
