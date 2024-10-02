--- content/app/content_main_runner_impl.cc.orig	2024-09-30 07:45:04 UTC
+++ content/app/content_main_runner_impl.cc
@@ -147,18 +147,20 @@
 #include "content/browser/posix_file_descriptor_info_impl.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_fork_delegate_linux.h"
 #endif
 
 #endif  // BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_path_watcher_inotify.h"
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "third_party/boringssl/src/include/openssl/crypto.h"
 #include "third_party/webrtc_overrides/init_webrtc.h"  // nogncheck
 
@@ -192,6 +194,10 @@
 #include "media/base/media_switches.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/system/sys_info.h"
+#endif
+
 #if BUILDFLAG(IS_ANDROID)
 #include "base/system/sys_info.h"
 #include "content/browser/android/battery_metrics.h"
@@ -400,7 +406,7 @@ void InitializeZygoteSandboxForBrowserProcess(
 }
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_PPAPI)
 // Loads the (native) libraries but does not initialize them (i.e., does not
@@ -438,7 +444,10 @@ void PreloadLibraryCdms() {
 
 void PreSandboxInit() {
   // Ensure the /dev/urandom is opened.
+  // we use arc4random
+#if !BUILDFLAG(IS_BSD)
   base::GetUrandomFD();
+#endif
 
   // May use sysinfo(), sched_getaffinity(), and open various /sys/ and /proc/
   // files.
@@ -450,9 +459,16 @@ void PreSandboxInit() {
   // https://boringssl.googlesource.com/boringssl/+/HEAD/SANDBOXING.md
   CRYPTO_pre_sandbox_init();
 
+#if BUILDFLAG(IS_BSD)
+  // "cache" the amount of physical memory before pledge(2)
+  base::SysInfo::AmountOfPhysicalMemoryMB();
+#endif
+
+#if !BUILDFLAG(IS_BSD)
   // Pre-read /proc/sys/fs/inotify/max_user_watches so it doesn't have to be
   // allowed by the sandbox.
   base::GetMaxNumberOfInotifyWatches();
+#endif
 
 #if BUILDFLAG(ENABLE_PPAPI)
   // Ensure access to the Pepper plugins before the sandbox is turned on.
@@ -764,7 +780,7 @@ RunOtherNamedProcessTypeMain(const std::string& proces
     unregister_thread_closure = base::HangWatcher::RegisterThread(
         base::HangWatcher::ThreadType::kMainThread);
     bool start_hang_watcher_now;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux/ChromeOS, the HangWatcher can't start until after the sandbox is
     // initialized, because the sandbox can't be started with multiple threads.
     // TODO(mpdenton): start the HangWatcher after the sandbox is initialized.
@@ -874,11 +890,10 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
                  base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   g_fds->Set(kCrashDumpSignal,
              kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #endif  // !BUILDFLAG(IS_WIN)
 
@@ -1055,8 +1070,20 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
       process_type == switches::kZygoteProcess) {
     PreSandboxInit();
   }
+#elif BUILDFLAG(IS_BSD)
+  PreSandboxInit();
 #endif
 
+#if BUILDFLAG(IS_BSD)
+  if (process_type.empty()) {
+    sandbox::policy::SandboxLinux::Options sandbox_options;
+    sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
+        sandbox::policy::SandboxTypeFromCommandLine(
+            *base::CommandLine::ForCurrentProcess()),
+        sandbox::policy::SandboxLinux::PreSandboxHook(), sandbox_options);
+  }
+#endif
+
   delegate_->SandboxInitialized(process_type);
 
 #if BUILDFLAG(USE_ZYGOTE)
@@ -1153,6 +1180,11 @@ int NO_STACK_PROTECTOR ContentMainRunnerImpl::Run() {
   content_main_params_.reset();
 
   RegisterMainThreadFactories();
+
+#if BUILDFLAG(IS_BSD)
+  if (!process_type.empty())
+    PreSandboxInit();
+#endif 
 
   if (process_type.empty())
     return RunBrowser(std::move(main_params), start_minimal_browser);
