--- base/trace_event/process_memory_dump.cc.orig	2024-08-26 12:06:38 UTC
+++ base/trace_event/process_memory_dump.cc
@@ -120,7 +120,7 @@ std::optional<size_t> ProcessMemoryDump::CountResident
 #if BUILDFLAG(IS_WIN)
   auto vec =
       base::HeapArray<PSAPI_WORKING_SET_EX_INFORMATION>::WithSize(max_vec_size);
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   auto vec = base::HeapArray<char>::WithSize(max_vec_size);
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
   auto vec = base::HeapArray<unsigned char>::WithSize(max_vec_size);
@@ -143,7 +143,7 @@ std::optional<size_t> ProcessMemoryDump::CountResident
 
     for (size_t i = 0; i < page_count; i++)
       resident_page_count += vec[i].VirtualAttributes.Valid;
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050620): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
