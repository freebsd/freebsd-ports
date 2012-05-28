--- content/app/content_main_runner.cc.orig	2012-04-29 20:37:46.000000000 +0300
+++ content/app/content_main_runner.cc	2012-04-29 20:37:58.000000000 +0300
@@ -353,7 +353,7 @@
     base::GlobalDescriptors* g_fds = base::GlobalDescriptors::GetInstance();
     g_fds->Set(kPrimaryIPCChannel,
                kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor);
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
 #endif
