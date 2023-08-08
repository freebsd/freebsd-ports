--- src/3rdparty/chromium/tools/memory/partition_allocator/inspect_utils.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/tools/memory/partition_allocator/inspect_utils.h
@@ -60,7 +60,7 @@ class RemoteProcessMemoryReader {
   const pid_t pid_;
   bool is_valid_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedFD mem_fd_;
 #elif BUILDFLAG(IS_MAC)
   task_t task_;
