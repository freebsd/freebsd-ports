--- base/threading/platform_thread_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ base/threading/platform_thread_posix.cc
@@ -75,7 +75,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     internal::PCScan::NotifyThreadCreated(internal::GetStackPointer());
 #endif
@@ -362,6 +362,9 @@ bool PlatformThread::CanChangeThreadPriority(ThreadPri
 // static
 void PlatformThread::SetCurrentThreadPriorityImpl(ThreadPriority priority) {
 #if BUILDFLAG(IS_NACL)
+  NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadPriorityForPlatform(priority))
