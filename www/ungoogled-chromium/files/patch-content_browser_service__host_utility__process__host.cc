--- content/browser/service_host/utility_process_host.cc.orig	2026-06-05 13:45:06 UTC
+++ content/browser/service_host/utility_process_host.cc
@@ -65,7 +65,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -99,7 +99,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -522,7 +522,7 @@ bool UtilityProcessHost::StartProcess() {
       GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The network service should have access to the parent directories
   // necessary for its usage.
   if (options_.sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -540,7 +540,7 @@ bool UtilityProcessHost::StartProcess() {
       video_capture::mojom::VideoCaptureService::Name_) {
     bool pass_gpu_buffer_flag =
         switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Check if NV12 GPU memory buffer supported at the same time.
     pass_gpu_buffer_flag =
         pass_gpu_buffer_flag &&
