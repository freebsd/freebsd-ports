--- src/timing.cpp.orig	2020-07-06 09:01:51 UTC
+++ src/timing.cpp
@@ -22,7 +22,7 @@ unsigned long GetTimerClock()
 {
   timespec ts;
 
-  clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
+  clock_gettime(CLOCK_MONOTONIC, &ts);
   // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
   // clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
 
