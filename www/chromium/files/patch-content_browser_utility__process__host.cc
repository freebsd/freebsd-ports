--- content/browser/utility_process_host.cc.orig	2024-11-14 07:57:23 UTC
+++ content/browser/utility_process_host.cc
@@ -62,7 +62,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -76,7 +76,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/task/sequenced_task_runner.h"
 #include "components/viz/host/gpu_client.h"
 #include "media/capture/capture_switches.h"
@@ -87,7 +87,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -153,7 +153,7 @@ UtilityProcessHost::UtilityProcessHost(std::unique_ptr
       name_(u"utility process"),
       file_data_(std::make_unique<ChildProcessLauncherFileData>()),
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       allowed_gpu_(false),
       gpu_client_(nullptr, base::OnTaskRunnerDeleter(nullptr)),
 #endif
@@ -213,7 +213,7 @@ void UtilityProcessHost::SetPreloadLibraries(
 
 void UtilityProcessHost::SetAllowGpuClient() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   allowed_gpu_ = true;
 #endif
 }
@@ -410,7 +410,7 @@ bool UtilityProcessHost::StartProcess() {
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -421,13 +421,13 @@ bool UtilityProcessHost::StartProcess() {
     }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
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
