--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -76,7 +76,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     internal::PCScan::NotifyThreadCreated(internal::GetStackPointer());
 #endif
@@ -365,6 +365,9 @@ void PlatformThread::SetCurrentThreadPriorityImpl(Thre
 // static
 void PlatformThread::SetCurrentThreadPriorityImpl(ThreadPriority priority) {
 #if BUILDFLAG(IS_NACL)
+  NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadPriorityForPlatform(priority))
