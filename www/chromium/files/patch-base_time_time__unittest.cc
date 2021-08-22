--- base/time/time_unittest.cc.orig	2021-07-19 18:45:05 UTC
+++ base/time/time_unittest.cc
@@ -2007,6 +2007,7 @@ TEST(TimeDelta, Overflows) {
   static_assert((kLargeDelta / 0.5).is_max(), "");
   static_assert((kLargeDelta / -0.5).is_min(), "");
 
+#if !defined(OS_BSD)
   static_assert(
       TimeDelta::Max() / kOneSecond == std::numeric_limits<double>::infinity(),
       "");
@@ -2035,6 +2036,7 @@ TEST(TimeDelta, Overflows) {
   static_assert(TimeDelta::Max() % -kOneSecond == TimeDelta::Max(), "");
   static_assert(TimeDelta::Min() % kOneSecond == TimeDelta::Min(), "");
   static_assert(TimeDelta::Min() % -kOneSecond == TimeDelta::Min(), "");
+#endif
 
   // Division by zero.
   static_assert((kOneSecond / 0).is_max(), "");
