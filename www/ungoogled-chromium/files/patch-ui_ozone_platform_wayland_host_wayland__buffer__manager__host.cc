--- ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc.orig	2026-02-15 10:01:45 UTC
+++ ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc
@@ -46,9 +46,13 @@ std::string NumberToString(uint32_t number) {
 }
 
 bool CheckImportExportFence() {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // DMA_BUF_IOCTL_{IMPORT,EXPORT}_SYNC_FILE was added in 6.0
   return base::SysInfo::KernelVersionNumber::Current() >=
          base::SysInfo::KernelVersionNumber(6, 0);
+#endif
 }
 
 }  // namespace
