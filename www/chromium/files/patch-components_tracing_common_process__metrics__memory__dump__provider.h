--- components/tracing/common/process_metrics_memory_dump_provider.h.orig	2017-06-05 19:03:06 UTC
+++ components/tracing/common/process_metrics_memory_dump_provider.h
@@ -57,7 +57,7 @@ class TRACING_EXPORT ProcessMetricsMemoryDumpProvider
 #elif defined(OS_WIN)
   FRIEND_TEST_ALL_PREFIXES(ProcessMetricsMemoryDumpProviderTest,
                            TestWinModuleReading);
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   FRIEND_TEST_ALL_PREFIXES(ProcessMetricsMemoryDumpProviderTest,
                            DoubleRegister);
 #endif
@@ -70,7 +70,7 @@ class TRACING_EXPORT ProcessMetricsMemoryDumpProvider
   static uint64_t rss_bytes_for_testing;
   static FactoryFunction factory_for_testing;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static FILE* proc_smaps_for_testing;
   static int fast_polling_statm_fd_for_testing;
 
