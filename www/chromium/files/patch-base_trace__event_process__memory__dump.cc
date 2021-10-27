--- base/trace_event/process_memory_dump.cc.orig	2021-09-14 01:51:47 UTC
+++ base/trace_event/process_memory_dump.cc
@@ -105,7 +105,7 @@ absl::optional<size_t> ProcessMemoryDump::CountResiden
 #if defined(OS_WIN)
   std::unique_ptr<PSAPI_WORKING_SET_EX_INFORMATION[]> vec(
       new PSAPI_WORKING_SET_EX_INFORMATION[max_vec_size]);
-#elif defined(OS_APPLE)
+#elif defined(OS_APPLE) || defined(OS_BSD)
   std::unique_ptr<char[]> vec(new char[max_vec_size]);
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
   std::unique_ptr<unsigned char[]> vec(new unsigned char[max_vec_size]);
