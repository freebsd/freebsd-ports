--- content/app/content_main_runner.cc.orig	2017-12-15 02:04:16.000000000 +0100
+++ content/app/content_main_runner.cc	2017-12-24 12:20:00.837482000 +0100
@@ -83,10 +83,10 @@
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
 
@@ -307,7 +307,7 @@
 };
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -432,7 +432,7 @@
   }
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
@@ -502,10 +502,10 @@
         kFieldTrialDescriptor + base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // OS_LINUX || OS_OPENBSD
+#endif  // OS_LINUX
 
 #endif  // !OS_WIN
 
