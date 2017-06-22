--- components/tracing/child/child_trace_message_filter.cc.orig	2017-06-05 19:03:06 UTC
+++ components/tracing/child/child_trace_message_filter.cc
@@ -35,7 +35,7 @@ void ChildTraceMessageFilter::OnFilterAdded(IPC::Chann
   sender_ = channel;
   sender_->Send(new TracingHostMsg_ChildSupportsTracing());
 
-#if !defined(OS_LINUX) && !defined(OS_NACL)
+#if !defined(OS_LINUX) && !defined(OS_NACL) && !defined(OS_BSD)
   // On linux the browser process takes care of dumping process metrics.
   // The child process is not allowed to do so due to BPF sandbox.
   tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
