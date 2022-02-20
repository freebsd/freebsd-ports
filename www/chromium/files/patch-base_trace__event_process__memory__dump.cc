--- base/trace_event/process_memory_dump.cc.orig	2022-02-07 13:39:41 UTC
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
@@ -127,7 +127,7 @@ absl::optional<size_t> ProcessMemoryDump::CountResiden
 
     for (size_t i = 0; i < page_count; i++)
       resident_page_count += vec[i].VirtualAttributes.Valid;
-#elif defined(OS_FUCHSIA)
+#elif defined(OS_FUCHSIA) | defined(OS_BSD)
     // TODO(fuchsia): Port, see https://crbug.com/706592.
     ALLOW_UNUSED_LOCAL(chunk_start);
     ALLOW_UNUSED_LOCAL(page_count);
