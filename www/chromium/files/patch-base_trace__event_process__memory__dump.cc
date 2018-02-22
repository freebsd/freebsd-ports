--- base/trace_event/process_memory_dump.cc.orig	2017-12-15 02:04:05.000000000 +0100
+++ base/trace_event/process_memory_dump.cc	2017-12-23 21:58:59.977492000 +0100
@@ -86,7 +86,7 @@
   const size_t kMaxChunkSize = 8 * 1024 * 1024;
   size_t max_vec_size =
       GetSystemPageCount(std::min(mapped_size, kMaxChunkSize), page_size);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<char[]> vec(new char[max_vec_size]);
 #elif defined(OS_WIN)
   std::unique_ptr<PSAPI_WORKING_SET_EX_INFORMATION[]> vec(
