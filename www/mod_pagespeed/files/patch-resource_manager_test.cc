--- net/instaweb/rewriter/resource_manager_test.cc.orig	2011-10-31 14:25:06.000000000 +0000
+++ net/instaweb/rewriter/resource_manager_test.cc	2011-10-31 18:56:11.000000000 +0000
@@ -339,7 +339,11 @@
   void VerifyWithinSecond(int64 time_a_ms, int64 time_b_ms) {
     // Note: need to pass in 1 * since otherwise we get a link failure
     // due to conversion of compile-time constant to const reference
+#if defined(__FreeBSD__)
+    EXPECT_GE(1 * Timer::kSecondMs, llabs(time_a_ms - time_b_ms));
+#else
     EXPECT_GE(1 * Timer::kSecondMs, std::abs(time_a_ms - time_b_ms));
+#endif
   }
 
   void VerifyValidCachedResult(const char* subtest_name, bool test_meta_data,
