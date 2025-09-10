--- base/threading/platform_thread_posix.cc.orig	2025-09-10 13:22:16 UTC
+++ base/threading/platform_thread_posix.cc
@@ -79,6 +79,7 @@ void* ThreadFunc(void* params) {
       base::DisallowSingleton();
     }
 
+#if !BUILDFLAG(IS_BSD)
 #if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
@@ -92,6 +93,7 @@ void* ThreadFunc(void* params) {
     // where they were created. This explicitly sets the priority of all new
     // threads.
     PlatformThread::SetCurrentThreadType(thread_params->thread_type);
+#endif
   }
 
   ThreadIdNameManager::GetInstance()->RegisterThread(
@@ -266,6 +268,8 @@ PlatformThreadId PlatformThreadBase::CurrentId() {
 
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return PlatformThreadId(pthread_self());
+#elif BUILDFLAG(IS_BSD)
+  return PlatformThreadId(reinterpret_cast<uint64_t>(pthread_self()));
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return PlatformThreadId(reinterpret_cast<int64_t>(pthread_self()));
 #endif
@@ -359,6 +363,9 @@ void PlatformThreadBase::Detach(PlatformThreadHandle t
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   if (from >= to) {
     // Decreasing thread priority on POSIX is always allowed.
     return true;
@@ -368,12 +375,18 @@ bool PlatformThreadBase::CanChangeThreadType(ThreadTyp
   }
 
   return internal::CanLowerNiceTo(internal::ThreadTypeToNiceValue(to));
+#endif
 }
 
 namespace internal {
 
 void SetCurrentThreadTypeImpl(ThreadType thread_type,
                               MessagePumpType pump_type_hint) {
+#if BUILDFLAG(IS_BSD)
+  // pledge(2) violation
+  NOTIMPLEMENTED();
+  return;
+#else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint)) {
     return;
   }
@@ -389,12 +402,17 @@ void SetCurrentThreadTypeImpl(ThreadType thread_type,
     DVPLOG(1) << "Failed to set nice value of thread ("
               << PlatformThread::CurrentId() << ") to " << nice_setting;
   }
+#endif
 }
 
 }  // namespace internal
 
 // static
 ThreadPriorityForTest PlatformThreadBase::GetCurrentThreadPriorityForTest() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return ThreadPriorityForTest::kNormal;
+#else
   // Mirrors SetCurrentThreadPriority()'s implementation.
   auto platform_specific_priority =
       internal::GetCurrentThreadPriorityForPlatformForTest();  // IN-TEST
@@ -405,6 +423,7 @@ ThreadPriorityForTest PlatformThreadBase::GetCurrentTh
   int nice_value = internal::GetCurrentThreadNiceValue();
 
   return internal::NiceValueToThreadPriorityForTest(nice_value);  // IN-TEST
+#endif
 }
 
 #endif  // !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA)
