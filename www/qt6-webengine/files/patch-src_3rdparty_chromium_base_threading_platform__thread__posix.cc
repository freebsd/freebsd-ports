--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -76,7 +76,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(USE_STARSCAN)
+#if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(USE_STARSCAN) && !BUILDFLAG(IS_BSD)
     partition_alloc::internal::PCScan::NotifyThreadCreated(
         partition_alloc::internal::GetStackPointer());
 #endif
@@ -374,6 +374,9 @@ void SetCurrentThreadTypeImpl(ThreadType thread_type,
                               MessagePumpType pump_type_hint) {
 #if BUILDFLAG(IS_NACL)
   NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
+   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint))
     return;
