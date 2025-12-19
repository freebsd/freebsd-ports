--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -79,11 +79,11 @@ void* ThreadFunc(void* params) {
       base::DisallowSingleton();
     }
 
-#if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && !BUILDFLAG(IS_BSD)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_APPLE)
     PlatformThread::SetCurrentThreadRealtimePeriodValue(
         delegate->GetRealtimePeriod());
@@ -270,6 +270,8 @@ PlatformThreadId PlatformThreadBase::CurrentId() {
   return reinterpret_cast<int32_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return pthread_self();
+#elif BUILDFLAG(IS_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return reinterpret_cast<int64_t>(pthread_self());
 #endif
@@ -363,7 +365,7 @@ bool PlatformThreadBase::CanChangeThreadType(ThreadTyp
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   return false;
 #else
   if (from >= to) {
@@ -384,6 +386,9 @@ void SetCurrentThreadTypeImpl(ThreadType thread_type,
                               MessagePumpType pump_type_hint) {
 #if BUILDFLAG(IS_NACL)
   NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
+   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint)) {
     return;
@@ -407,7 +412,7 @@ ThreadPriorityForTest PlatformThreadBase::GetCurrentTh
 
 // static
 ThreadPriorityForTest PlatformThreadBase::GetCurrentThreadPriorityForTest() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return ThreadPriorityForTest::kNormal;
 #else
