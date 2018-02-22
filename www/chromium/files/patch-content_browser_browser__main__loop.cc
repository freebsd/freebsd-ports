--- content/browser/browser_main_loop.cc.orig	2018-01-04 21:05:49.000000000 +0100
+++ content/browser/browser_main_loop.cc	2018-01-21 04:50:16.739260000 +0100
@@ -198,7 +198,7 @@
 #include "base/fuchsia/default_job.h"
 #endif  // defined(OS_FUCHSIA)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/browser/sandbox_host_linux.h"
 #include "content/browser/zygote_host/zygote_host_impl_linux.h"
 
@@ -232,6 +232,11 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/common/sandbox_linux/sandbox_linux.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -249,7 +254,7 @@
 }
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
 void SetupSandbox(const base::CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   // SandboxHostLinux needs to be initialized even if the sandbox and
@@ -272,7 +277,7 @@
       generic_zygote->GetSandboxStatus());
 }
 #endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-        // !defined(OS_FUCHSIA)
+        // !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
 #if defined(USE_GLIB)
 static void GLibLogHandler(const gchar* log_domain,
@@ -574,10 +579,15 @@
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
+#elif defined(OS_BSD)
+  SandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  fds_to_map.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
 #if defined(USE_X11)
@@ -1619,12 +1629,12 @@
       base::WrapUnique<SwapMetricsDriver::Delegate>(
           new SwapMetricsDelegateUma()));
 
-#if !defined(OS_FUCHSIA)
+#if !defined(OS_FUCHSIA) && !defined(OS_BSD)
   swap_metrics_driver_ =
       SwapMetricsDriver::Create(std::move(delegate), kSwapMetricsInterval);
   if (swap_metrics_driver_)
     swap_metrics_driver_->Start();
-#endif  // !defined(OS_FUCHSIA)
+#endif  // !defined(OS_FUCHSIA) && !defined(OS_BSD)
 }
 
 bool BrowserMainLoop::InitializeToolkit() {
