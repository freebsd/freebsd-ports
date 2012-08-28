--- content/app/content_main_runner.cc.orig	2012-07-18 10:01:24.000000000 +0300
+++ content/app/content_main_runner.cc	2012-07-25 21:01:19.000000000 +0300
@@ -462,7 +462,7 @@
                kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
 #endif
