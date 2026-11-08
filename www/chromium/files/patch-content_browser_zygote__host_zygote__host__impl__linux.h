--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2026-10-18 13:29:39 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -51,12 +51,14 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
       base::ScopedFD* control_fd,
       base::FileHandleMappingVector additional_remapped_fds);
 
+#if !BUILDFLAG(IS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
 #if BUILDFLAG(IS_CHROMEOS)
   void ReinitializeLogging(uint32_t logging_dest,
                            base::PlatformFile log_file_fd) override;
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
   bool HasZygote() { return has_zygote_; }
 
@@ -77,9 +79,11 @@ class CONTENT_EXPORT ZygoteHostImpl : public ZygoteHos
   // other threads are created.
   bool has_zygote_ = false;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   base::Lock zygote_pids_lock_;
