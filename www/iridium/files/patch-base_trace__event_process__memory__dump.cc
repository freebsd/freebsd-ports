--- base/trace_event/process_memory_dump.cc.orig	2018-05-09 21:05:33.000000000 +0200
+++ base/trace_event/process_memory_dump.cc	2018-08-16 02:36:46.780728000 +0200
@@ -92,7 +92,7 @@
   const size_t kMaxChunkSize = 8 * 1024 * 1024;
   size_t max_vec_size =
       GetSystemPageCount(std::min(mapped_size, kMaxChunkSize), page_size);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<char[]> vec(new char[max_vec_size]);
 #elif defined(OS_WIN)
   std::unique_ptr<PSAPI_WORKING_SET_EX_INFORMATION[]> vec(
