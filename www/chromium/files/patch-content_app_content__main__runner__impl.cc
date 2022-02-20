--- content/app/content_main_runner_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ content/app/content_main_runner_impl.cc
@@ -131,13 +131,13 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 #include "content/public/common/zygote/zygote_fork_delegate_linux.h"
 #endif
 
 #endif  // OS_POSIX || OS_FUCHSIA
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
@@ -171,6 +171,12 @@
 #include "media/base/media_switches.h"
 #endif
 
+#if defined(OS_BSD)
+#include "base/system/sys_info.h"
+#include "content/public/common/sandbox_init.h"
+#include "sandbox/policy/linux/sandbox_linux.h"
+#endif
+
 #if defined(OS_ANDROID)
 #include "base/system/sys_info.h"
 #include "components/power_scheduler/power_scheduler.h"
@@ -344,7 +350,7 @@ void InitializeZygoteSandboxForBrowserProcess(
 }
 #endif  // BUILDFLAG(USE_ZYGOTE_HANDLE)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PLUGINS)
 // Loads the (native) libraries but does not initialize them (i.e., does not
@@ -380,11 +386,14 @@ void PreloadLibraryCdms() {
 }
 #endif  // BUILDFLAG(ENABLE_LIBRARY_CDMS)
 
-#if BUILDFLAG(USE_ZYGOTE_HANDLE)
+#if BUILDFLAG(USE_ZYGOTE_HANDLE) || defined(OS_BSD)
 void PreSandboxInit() {
+  // arc4random
+#if !defined(OS_BSD) 
   // Pre-acquire resources needed by BoringSSL. See
   // https://boringssl.googlesource.com/boringssl/+/HEAD/SANDBOXING.md
   CRYPTO_pre_sandbox_init();
+#endif
 
 #if BUILDFLAG(ENABLE_PLUGINS)
   // Ensure access to the Pepper plugins before the sandbox is turned on.
@@ -396,6 +405,11 @@ void PreSandboxInit() {
 #endif
   InitializeWebRtcModule();
 
+#if defined(OS_BSD)
+  // "cache" the amount of physical memory before pledge(2)
+  base::SysInfo::AmountOfPhysicalMemoryMB();
+#endif
+
   // Set the android SkFontMgr for blink. We need to ensure this is done
   // before the sandbox is initialized to allow the font manager to access
   // font configuration files on disk.
@@ -565,7 +579,7 @@ int NO_STACK_PROTECTOR RunZygote(ContentMainDelegate* 
   delegate->ZygoteStarting(&zygote_fork_delegates);
   media::InitializeMediaLibrary();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   PreSandboxInit();
 #endif
 
@@ -741,10 +755,10 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
              kFieldTrialDescriptor + base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS)
   g_fds->Set(kCrashDumpSignal,
              kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
 #endif  // !OS_WIN
 
@@ -933,6 +947,16 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
   }
 #endif
 
+#if defined(OS_BSD)
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
 
 #if BUILDFLAG(USE_ZYGOTE_HANDLE)
@@ -988,7 +1012,7 @@ int NO_STACK_PROTECTOR ContentMainRunnerImpl::Run() {
       mojo::core::InitFeatures();
     }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // If dynamic Mojo Core is being used, ensure that it's loaded very early in
     // the child/zygote process, before any sandbox is initialized. The library
     // is not fully initialized with IPC support until a ChildProcess is later
@@ -1021,6 +1045,11 @@ int NO_STACK_PROTECTOR ContentMainRunnerImpl::Run() {
   content_main_params_.reset();
 
   RegisterMainThreadFactories();
+
+#if defined(OS_BSD)
+  if (!process_type.empty())
+    PreSandboxInit();
+#endif 
 
   if (process_type.empty())
     return RunBrowser(std::move(main_params), start_minimal_browser);
