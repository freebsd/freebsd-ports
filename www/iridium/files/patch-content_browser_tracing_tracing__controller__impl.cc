--- content/browser/tracing/tracing_controller_impl.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/tracing/tracing_controller_impl.cc
@@ -476,7 +476,7 @@ void TracingControllerImpl::AddTraceMess
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
@@ -504,7 +504,7 @@ void TracingControllerImpl::RemoveTraceM
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   tracing::ProcessMetricsMemoryDumpProvider::UnregisterForProcess(
       trace_message_filter->peer_pid());
 #endif
