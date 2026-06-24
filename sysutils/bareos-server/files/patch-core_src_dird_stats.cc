--- core/src/dird/stats.cc.orig	2026-06-24 10:10:44 UTC
+++ core/src/dird/stats.cc
@@ -141,7 +141,7 @@ extern "C" void* statistics_thread(void*)
   while (!quit) {
     now = (utime_t)time(NULL);
 
-    Dmsg1(200, "statistics_thread: Doing work at %" PRItime "\n", now);
+    Dmsg1(200, "statistics_thread: Doing work at %lld\n", (long long)now);
 
     if (JobCount() == 0) {
       if (!need_flush) {
