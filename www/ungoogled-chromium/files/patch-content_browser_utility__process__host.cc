--- content/browser/utility_process_host.cc.orig	2024-04-23 07:42:17 UTC
+++ content/browser/utility_process_host.cc
@@ -61,7 +61,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -75,7 +75,7 @@
 #include "services/network/public/mojom/network_service.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "base/task/sequenced_task_runner.h"
 #include "components/viz/host/gpu_client.h"
 #include "media/capture/capture_switches.h"
@@ -86,7 +86,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -150,7 +150,7 @@ UtilityProcessHost::UtilityProcessHost(std::unique_ptr
       started_(false),
       name_(u"utility process"),
       file_data_(std::make_unique<ChildProcessLauncherFileData>()),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       allowed_gpu_(false),
       gpu_client_(nullptr, base::OnTaskRunnerDeleter(nullptr)),
 #endif
@@ -234,7 +234,7 @@ void UtilityProcessHost::SetPinUser32() {
 #endif  // BUILDFLAG(IS_WIN)
 
 void UtilityProcessHost::SetAllowGpuClient() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   allowed_gpu_ = true;
 #endif
 }
@@ -434,7 +434,7 @@ bool UtilityProcessHost::StartProcess() {
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload());
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -445,13 +445,13 @@ bool UtilityProcessHost::StartProcess() {
     }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     // Pass `kVideoCaptureUseGpuMemoryBuffer` flag to video capture service only
     // when the video capture use GPU memory buffer enabled.
     if (metrics_name_ == video_capture::mojom::VideoCaptureService::Name_) {
       bool pass_gpu_buffer_flag =
           switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if NV12 GPU memory buffer supported at the same time.
       pass_gpu_buffer_flag =
           pass_gpu_buffer_flag &&
