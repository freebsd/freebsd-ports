--- content/app/content_main.cc.orig	2012-02-01 21:47:17.000000000 +0200
+++ content/app/content_main.cc	2012-02-01 21:47:28.000000000 +0200
@@ -316,7 +316,7 @@
   base::GlobalDescriptors* g_fds = base::GlobalDescriptors::GetInstance();
   g_fds->Set(kPrimaryIPCChannel,
              kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor);
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   g_fds->Set(kCrashDumpSignal,
              kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
 #endif
