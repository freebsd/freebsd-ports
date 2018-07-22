--- content/app/content_main_runner.cc.orig	2018-06-13 00:10:16.000000000 +0200
+++ content/app/content_main_runner.cc	2018-07-19 00:17:30.909304000 +0200
@@ -84,10 +84,10 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/common/zygote_fork_delegate_linux.h"
 #endif
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/zygote/zygote_main.h"
 #include "sandbox/linux/services/libc_interceptor.h"
 #endif
@@ -153,7 +153,7 @@
 namespace content {
 extern int GpuMain(const content::MainFunctionParams&);
 #if BUILDFLAG(ENABLE_PLUGINS)
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 extern int PluginMain(const content::MainFunctionParams&);
 #endif
 extern int PpapiPluginMain(const MainFunctionParams&);
@@ -702,10 +702,10 @@
         kFieldTrialDescriptor + base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // OS_LINUX || OS_OPENBSD
+#endif  // OS_LINUX
 
 #endif  // !OS_WIN
 
