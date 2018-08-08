--- content/app/content_main_runner_impl.cc.orig	2018-08-01 00:08:43.000000000 +0200
+++ content/app/content_main_runner_impl.cc	2018-08-04 18:50:49.262605000 +0200
@@ -83,10 +83,10 @@
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
@@ -150,7 +150,7 @@
 namespace content {
 extern int GpuMain(const content::MainFunctionParams&);
 #if BUILDFLAG(ENABLE_PLUGINS)
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 extern int PluginMain(const content::MainFunctionParams&);
 #endif
 extern int PpapiPluginMain(const MainFunctionParams&);
@@ -722,11 +722,11 @@
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
 
