--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2017-09-07 07:15:01.296724000 +0200
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h	2017-09-07 07:15:17.711160000 +0200
@@ -21,7 +21,7 @@
  private:
   FRIEND_TEST_ALL_PREFIXES(OSMetricsTest, ParseProcSmaps);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
 #endif  // defined(OS_LINUX)
 };
