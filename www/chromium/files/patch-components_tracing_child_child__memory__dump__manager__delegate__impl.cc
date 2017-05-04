--- components/tracing/child/child_memory_dump_manager_delegate_impl.cc.orig	2017-04-19 19:06:33 UTC
+++ components/tracing/child/child_memory_dump_manager_delegate_impl.cc
@@ -52,7 +52,7 @@ void ChildMemoryDumpManagerDelegateImpl:
     base::trace_event::MemoryDumpManager::GetInstance()->Initialize(
       this /* delegate */, false /* is_coordinator */);
 
-#if !defined(OS_LINUX) && !defined(OS_NACL)
+#if !defined(OS_LINUX) && !defined(OS_NACL) && !defined(OS_BSD)
     // On linux the browser process takes care of dumping process metrics.
     // The child process is not allowed to do so due to BPF sandbox.
     tracing::ProcessMetricsMemoryDumpProvider::RegisterForProcess(
