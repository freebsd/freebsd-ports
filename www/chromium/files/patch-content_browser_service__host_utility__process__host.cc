--- content/browser/service_host/utility_process_host.cc.orig	2025-09-06 10:01:20 UTC
+++ content/browser/service_host/utility_process_host.cc
@@ -68,7 +68,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -97,7 +97,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -494,7 +494,7 @@ bool UtilityProcessHost::StartProcess() {
       GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The network service should have access to the parent directories
   // necessary for its usage.
   if (options_.sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -512,7 +512,7 @@ bool UtilityProcessHost::StartProcess() {
       video_capture::mojom::VideoCaptureService::Name_) {
     bool pass_gpu_buffer_flag =
         switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Check if NV12 GPU memory buffer supported at the same time.
     pass_gpu_buffer_flag =
         pass_gpu_buffer_flag &&
