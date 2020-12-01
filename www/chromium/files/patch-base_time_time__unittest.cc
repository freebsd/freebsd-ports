--- base/time/time_unittest.cc.orig	2020-11-16 17:58:27 UTC
+++ base/time/time_unittest.cc
@@ -1969,6 +1969,7 @@ TEST(TimeDelta, Overflows) {
   EXPECT_TRUE((kLargeDelta / 0.5).is_max());
   EXPECT_TRUE((kLargeDelta / -0.5).is_min());
 
+#if !defined(OS_BSD)
   static_assert(
       TimeDelta::Max() / kOneSecond == std::numeric_limits<double>::infinity(),
       "");
@@ -1997,6 +1998,7 @@ TEST(TimeDelta, Overflows) {
   static_assert(TimeDelta::Max() % -kOneSecond == TimeDelta::Max(), "");
   static_assert(TimeDelta::Min() % kOneSecond == TimeDelta::Min(), "");
   static_assert(TimeDelta::Min() % -kOneSecond == TimeDelta::Min(), "");
+#endif
 
   // Division by zero.
   static_assert((kOneSecond / 0).is_max(), "");
