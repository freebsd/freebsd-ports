--- base/posix/can_lower_nice_to.cc.orig	2019-03-11 22:00:51 UTC
+++ base/posix/can_lower_nice_to.cc
@@ -31,6 +31,9 @@ bool CanLowerNiceTo(int nice_value) {
   if (geteuid() == 0)
     return true;
 
+#if defined(OS_BSD)
+  return false;
+#else
   // 2. Skip checking the CAP_SYS_NICE permission because it would require
   // libcap.so.
 
@@ -54,6 +57,7 @@ bool CanLowerNiceTo(int nice_value) {
   // And lowering niceness to |nice_value| is allowed if it is greater than or
   // equal to the limit:
   return nice_value >= lowest_nice_allowed;
+#endif
 }
 
 }  // namespace internal
