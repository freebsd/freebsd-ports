--- src/timing.cpp.orig	2020-01-16 05:36:23 UTC
+++ src/timing.cpp
@@ -23,7 +23,7 @@ unsigned long GetTimerClock()
   timespec ts;
 
 
-  clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
+  clock_gettime(CLOCK_MONOTONIC, &ts);
   //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
   //clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
 
