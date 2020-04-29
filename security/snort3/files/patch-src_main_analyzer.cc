--- src/main/analyzer.cc.orig	2020-04-23 16:12:51 UTC
+++ src/main/analyzer.cc
@@ -96,7 +96,7 @@ class RetryQueue (public)
     RetryQueue(unsigned interval_ms)
     {
         assert(interval_ms > 0);
-        interval = { interval_ms / 1000, static_cast<suseconds_t>((interval_ms % 1000) * 1000) };
+        interval = { static_cast<time_t>(interval_ms / 1000), static_cast<suseconds_t>( (interval_ms % 1000) * 1000 )};
     }
 
     ~RetryQueue()
@@ -552,7 +552,7 @@ void Analyzer::idle()
     struct timeval now, increment;
     unsigned int timeout = SnortConfig::get_conf()->daq_config->timeout;
     packet_gettimeofday(&now);
-    increment = { timeout / 1000, static_cast<suseconds_t>((timeout % 1000) * 1000) };
+    increment = { static_cast<time_t>(timeout / 1000), static_cast<suseconds_t>((timeout % 1000) * 1000) };
     timeradd(&now, &increment, &now);
     packet_time_update(&now);
 
