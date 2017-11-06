--- content/browser/tracing/tracing_controller_impl.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/tracing/tracing_controller_impl.cc
@@ -412,7 +412,7 @@ void TracingControllerImpl::AddTraceMessageFilter(
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the browser process dumps process metrics for child process due to
   // sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
@@ -440,7 +440,7 @@ void TracingControllerImpl::RemoveTraceMessageFilter(
     return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   tracing::ProcessMetricsMemoryDumpProvider::UnregisterForProcess(
       trace_message_filter->peer_pid());
 #endif
