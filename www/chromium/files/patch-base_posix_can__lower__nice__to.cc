--- base/posix/can_lower_nice_to.cc.orig	2018-12-12 22:56:01.000000000 +0100
+++ base/posix/can_lower_nice_to.cc	2018-12-16 00:34:34.602103000 +0100
@@ -31,6 +31,9 @@
   if (geteuid() == 0)
     return true;
 
+#if defined(OS_BSD)
+  return false;
+#else
   // 2. Skip checking the CAP_SYS_NICE permission because it would require
   // libcap.so.
 
@@ -54,6 +57,7 @@
   // And lowering niceness to |nice_value| is allowed if it is greater than or
   // equal to the limit:
   return nice_value >= lowest_nice_allowed;
+#endif
 }
 
 }  // namespace internal
