--- base/trace_event/process_memory_dump.cc.orig	2024-03-22 14:16:19 UTC
+++ base/trace_event/process_memory_dump.cc
@@ -113,7 +113,7 @@ absl::optional<size_t> ProcessMemoryDump::CountResiden
 #if BUILDFLAG(IS_WIN)
   std::unique_ptr<PSAPI_WORKING_SET_EX_INFORMATION[]> vec(
       new PSAPI_WORKING_SET_EX_INFORMATION[max_vec_size]);
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   std::unique_ptr<char[]> vec(new char[max_vec_size]);
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
   std::unique_ptr<unsigned char[]> vec(new unsigned char[max_vec_size]);
@@ -135,7 +135,7 @@ absl::optional<size_t> ProcessMemoryDump::CountResiden
 
     for (size_t i = 0; i < page_count; i++)
       resident_page_count += vec[i].VirtualAttributes.Valid;
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/851760): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
