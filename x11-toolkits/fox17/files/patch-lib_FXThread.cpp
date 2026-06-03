--- lib/FXThread.cpp.orig	2025-06-26 02:08:06 UTC
+++ lib/FXThread.cpp
@@ -386,7 +386,7 @@ FXTime FXThread::ticks(){
   tbl&=-(FXint)(tbu0==tbu1);
   return (((FXTime)tbu1) << 32) | tbl;
 #elif (_POSIX_C_SOURCE >= 199309L)
-  const NSTime seconds=1000000000;
+  const FXTime seconds=1000000000;
   struct timespec ts;
   clock_gettime(CLOCK_MONOTONIC,&ts);   // Monotonic: no jumps!
   return ts.tv_sec*seconds+ts.tv_nsec;
