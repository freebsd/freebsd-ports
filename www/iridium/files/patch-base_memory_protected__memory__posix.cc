--- base/memory/protected_memory_posix.cc.orig	2025-12-10 15:04:57 UTC
+++ base/memory/protected_memory_posix.cc
@@ -6,7 +6,7 @@
 
 #include <sys/mman.h>
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -34,7 +34,7 @@ bool SetMemory(void* start, void* end, int prot) {
 }  // namespace
 
 namespace internal {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void CheckMemoryReadOnly(const void* ptr) {
   const uintptr_t page_start =
       bits::AlignDown(reinterpret_cast<uintptr_t>(ptr), GetPageSize());
