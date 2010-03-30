--- gavl/timer.c.orig	2010-03-30 13:33:59.510537263 +0200
+++ gavl/timer.c	2010-03-30 13:33:49.571212409 +0200
@@ -109,7 +109,14 @@
 uint64_t gavl_benchmark_get_time(int config_flags)
   {
   struct timespec ts;
+#if defined(CLOCK_PROCESS_CPUTIME_ID)
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
+#elif defined(CLOCK_PROF)
+  clock_gettime(CLOCK_PROF, &ts);
+#else
+  clock_gettime(CLOCK_REALTIME, &ts);
+#endif
+
   return (uint64_t)(ts.tv_sec) * 1000000000 + ts.tv_nsec;
   }
 
