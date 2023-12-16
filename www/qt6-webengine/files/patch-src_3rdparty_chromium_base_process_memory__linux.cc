--- src/3rdparty/chromium/base/process/memory_linux.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/process/memory_linux.cc
@@ -20,6 +20,7 @@
 
 namespace base {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 void ReleaseReservationOrTerminate() {
@@ -29,12 +30,14 @@ void ReleaseReservationOrTerminate() {
 }
 
 }  // namespace
+#endif
 
 void EnableTerminationOnHeapCorruption() {
   // On Linux, there nothing to do AFAIK.
 }
 
 void EnableTerminationOnOutOfMemory() {
+#if !BUILDFLAG(IS_BSD)
   // Set the new-out of memory handler.
   std::set_new_handler(&ReleaseReservationOrTerminate);
   // If we're using glibc's allocator, the above functions will override
@@ -43,8 +46,10 @@ void EnableTerminationOnOutOfMemory() {
 #if BUILDFLAG(USE_ALLOCATOR_SHIM)
   allocator_shim::SetCallNewHandlerOnMallocFailure(true);
 #endif
+#endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 // ScopedAllowBlocking() has private constructor and it can only be used in
 // friend classes/functions. Declaring a class is easier in this situation to
 // avoid adding more dependency to thread_restrictions.h because of the
@@ -104,6 +109,7 @@ bool AdjustOOMScoreHelper::AdjustOOMScore(ProcessId pr
 bool AdjustOOMScore(ProcessId process, int score) {
   return AdjustOOMScoreHelper::AdjustOOMScore(process, score);
 }
+#endif
 
 bool UncheckedMalloc(size_t size, void** result) {
 #if BUILDFLAG(USE_ALLOCATOR_SHIM)
