--- net/instaweb/rewriter/resource_manager_test.cc.orig	2011-09-29 13:52:19.000000000 +0000
+++ net/instaweb/rewriter/resource_manager_test.cc	2011-09-29 13:52:27.000000000 +0000
@@ -323,7 +323,7 @@
   void VerifyWithinSecond(int64 time_a_ms, int64 time_b_ms) {
     // Note: need to pass in 1 * since otherwise we get a link failure
     // due to conversion of compile-time constant to const reference
-    EXPECT_GE(1 * Timer::kSecondMs, std::abs(time_a_ms - time_b_ms));
+    EXPECT_GE(1 * Timer::kSecondMs, llabs(time_a_ms - time_b_ms));
   }
 
   void VerifyValidCachedResult(const char* subtest_name, bool test_meta_data,
