--- src/3rdparty/chromium/content/browser/tracing/tracing_controller_impl.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/tracing/tracing_controller_impl.cc
@@ -475,7 +475,7 @@ void TracingControllerImpl::AddTraceMess
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
