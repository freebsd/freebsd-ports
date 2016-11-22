--- content/browser/tracing/tracing_controller_impl.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/tracing/tracing_controller_impl.cc	2016-08-18 02:46:09.991782000 +0300
@@ -496,7 +496,7 @@
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
