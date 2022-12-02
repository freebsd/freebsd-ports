--- base/threading/platform_thread_posix.cc.orig	2022-12-02 17:56:32 UTC
+++ base/threading/platform_thread_posix.cc
@@ -78,7 +78,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(STARSCAN)
     partition_alloc::internal::PCScan::NotifyThreadCreated(
         partition_alloc::internal::GetStackPointer());
@@ -380,6 +380,9 @@ void SetCurrentThreadTypeImpl(ThreadType thread_type,
                               MessagePumpType pump_type_hint) {
 #if BUILDFLAG(IS_NACL)
   NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
+   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint))
     return;
