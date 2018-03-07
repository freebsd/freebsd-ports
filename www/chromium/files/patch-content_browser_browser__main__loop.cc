--- content/browser/browser_main_loop.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/browser/browser_main_loop.cc	2018-03-04 10:01:31.265940000 +0100
@@ -206,7 +206,7 @@
 #include "base/fuchsia/default_job.h"
 #endif  // defined(OS_FUCHSIA)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/browser/sandbox_host_linux.h"
 #include "content/browser/zygote_host/zygote_host_impl_linux.h"
 
@@ -244,6 +244,11 @@
 #include "services/ui/common/image_cursors_set.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -253,7 +258,7 @@
 namespace {
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
 void SetupSandbox(const base::CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   // SandboxHostLinux needs to be initialized even if the sandbox and
@@ -276,7 +281,7 @@
       generic_zygote->GetSandboxStatus());
 }
 #endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-        // !defined(OS_FUCHSIA)
+        // !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
 #if defined(USE_GLIB)
 static void GLibLogHandler(const gchar* log_domain,
@@ -619,10 +624,15 @@
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
@@ -1691,12 +1701,12 @@
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
