--- base/allocator/partition_allocator/partition_alloc_base/debug/stack_trace_posix.cc.orig	2023-11-22 14:00:11 UTC
+++ base/allocator/partition_allocator/partition_alloc_base/debug/stack_trace_posix.cc
@@ -12,11 +12,11 @@
 #include <string.h>
 #include <unistd.h>
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 #include <link.h>  // For ElfW() macro.
 #endif
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 #define HAVE_DLADDR
 #include <dlfcn.h>
 #endif
@@ -25,7 +25,7 @@ namespace partition_alloc::internal::base::debug {
 
 namespace {
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 
 constexpr size_t kBufferSize = 4096u;
 
@@ -359,7 +359,7 @@ void PrintStackTraceInternal(const void** trace, size_
 }
 #endif  // !BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 // Since /proc/self/maps is not available, use dladdr() to obtain module
 // names and offsets inside the modules from the given addresses.
 void PrintStackTraceInternal(const void* const* trace, size_t size) {
