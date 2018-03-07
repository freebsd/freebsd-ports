--- content/app/content_main_runner.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/app/content_main_runner.cc	2018-03-03 23:04:17.370076000 +0100
@@ -82,10 +82,10 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/common/zygote_fork_delegate_linux.h"
 #endif
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/zygote/zygote_main.h"
 #endif
 
@@ -429,7 +429,7 @@
   }
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
@@ -499,10 +499,10 @@
         kFieldTrialDescriptor + base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // OS_LINUX || OS_OPENBSD
+#endif  // OS_LINUX
 
 #endif  // !OS_WIN
 
