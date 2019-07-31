--- src/main/analyzer.cc.orig	2019-07-31 10:41:21 UTC
+++ src/main/analyzer.cc
@@ -94,7 +94,7 @@ class RetryQueue (public)
     RetryQueue(unsigned interval_ms)
     {
         assert(interval_ms > 0);
-        interval = { interval_ms / 1000, (interval_ms % 1000) * 1000 };
+        interval = { static_cast<time_t>(interval_ms / 1000), static_cast<suseconds_t>( (interval_ms % 1000) * 1000 )};
     }
 
     ~RetryQueue()
