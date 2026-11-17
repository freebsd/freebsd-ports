--- src/content/browser/zygote_host/zygote_host_impl_linux.h.orig	2026-10-20 02:47:55 UTC
+++ src/content/browser/zygote_host/zygote_host_impl_linux.h
@@ -17,7 +17,13 @@
 #include "base/process/process_handle.h"
 #include "base/synchronization/lock.h"
 #include "content/common/content_export.h"
+#if BUILDFLAG(IS_BSD)
+// Only for ZygoteLaunchCompletionCallback: zygote_handle_impl_linux.h needs
+// USE_ZYGOTE, which the BSDs do not have.
+#include "content/common/zygote/zygote_communication_linux.h"
+#else
 #include "content/common/zygote/zygote_handle_impl_linux.h"
+#endif
 #include "content/public/browser/zygote_host/zygote_host_linux.h"
 
 #if BUILDFLAG(IS_CHROMEOS)
@@ -50,12 +56,14 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
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
 
@@ -76,9 +84,11 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
   // other threads are created.
   bool has_zygote_ = false;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
