--- src/3rdparty/chromium/base/trace_event/process_memory_dump.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/base/trace_event/process_memory_dump.cc
@@ -52,7 +52,7 @@ size_t ProcessMemoryDump::CountResidentB
     const size_t page_count = (chunk_size + page_size - 1) / page_size;
     size_t resident_page_count = 0;
 
-#if defined(OS_MACOSX) || defined(OS_IOS)
+#if defined(OS_MACOSX) || defined(OS_IOS) || defined(OS_BSD)
     std::vector<char> vec(page_count + 1);
     // mincore in MAC does not fail with EAGAIN.
     result = mincore(chunk_start, chunk_size, vec.data());
@@ -61,7 +61,7 @@ size_t ProcessMemoryDump::CountResidentB
 
     for (size_t i = 0; i < page_count; i++)
       resident_page_count += vec[i] & MINCORE_INCORE ? 1 : 0;
-#else   // defined(OS_MACOSX) || defined(OS_IOS)
+#else   // defined(OS_MACOSX) || defined(OS_IOS) || defined(OS_BSD)
     std::vector<unsigned char> vec(page_count + 1);
     int error_counter = 0;
     // HANDLE_EINTR tries for 100 times. So following the same pattern.
@@ -73,7 +73,7 @@ size_t ProcessMemoryDump::CountResidentB
 
     for (size_t i = 0; i < page_count; i++)
       resident_page_count += vec[i];
-#endif  // defined(OS_MACOSX) || defined(OS_IOS)
+#endif  // defined(OS_MACOSX) || defined(OS_IOS) || defined(OS_BSD)
 
     total_resident_size += resident_page_count * page_size;
     offset += kMaxChunkSize;
