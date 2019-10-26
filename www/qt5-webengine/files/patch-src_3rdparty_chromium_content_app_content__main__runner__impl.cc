--- src/3rdparty/chromium/content/app/content_main_runner_impl.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/app/content_main_runner_impl.cc
@@ -93,17 +93,17 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "services/service_manager/zygote/common/zygote_fork_delegate_linux.h"
 #endif
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "services/service_manager/zygote/zygote_main.h"
 #endif
 
 #endif  // OS_POSIX || OS_FUCHSIA
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
@@ -126,7 +126,7 @@
 #if BUILDFLAG(ENABLE_WEBRTC)
 #include "third_party/webrtc_overrides/init_webrtc.h"  // nogncheck
 #endif
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
 #if !defined(CHROME_MULTIPLE_DLL_BROWSER)
 #include "content/child/field_trial.h"
@@ -314,7 +314,7 @@ void InitializeZygoteSandboxForBrowserProcess(
 }
 #endif  // BUILDFLAG(USE_ZYGOTE_HANDLE)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_PLUGINS)
 // Loads the (native) libraries but does not initialize them (i.e., does not
@@ -413,7 +413,7 @@ void PreSandboxInit() {
 }
 #endif  // BUILDFLAG(USE_ZYGOTE_HANDLE)
 
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
 }  // namespace
 
@@ -471,7 +471,7 @@ int RunZygote(ContentMainDelegate* delegate) {
   delegate->ZygoteStarting(&zygote_fork_delegates);
   media::InitializeMediaLibrary();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   PreSandboxInit();
 #endif
 
@@ -644,11 +644,11 @@ int ContentMainRunnerImpl::Initialize(const ContentMai
                    base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
     g_fds->Set(service_manager::kCrashDumpSignal,
                service_manager::kCrashDumpSignal +
                    base::GlobalDescriptors::kBaseDescriptor);
-#endif  // OS_LINUX || OS_OPENBSD
+#endif  // OS_LINUX
 
 #endif  // !OS_WIN
 
