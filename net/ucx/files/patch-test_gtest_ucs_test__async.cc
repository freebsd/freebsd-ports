--- test/gtest/ucs/test_async.cc.orig	2026-06-08 19:48:30 UTC
+++ test/gtest/ucs/test_async.cc
@@ -544,7 +544,7 @@ UCS_TEST_P(test_async, many_timers) {
     const int max_timers = ucs_max(10, 250 / ucs::test_time_multiplier());
 
     std::vector<int> timers;
-    timers.reserve(max_timers);
+    timers.resize(max_timers);
 
     for (int count = 0; count < max_iters; ++count) {
         for (int count2 = 0; count2 < max_timers; ++count2) {
