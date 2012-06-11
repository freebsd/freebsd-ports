--- base/debug/stack_trace_posix.cc.orig	2012-06-11 23:22:13.000000000 +0300
+++ base/debug/stack_trace_posix.cc	2012-06-12 00:09:38.000000000 +0300
@@ -153,6 +153,11 @@
     count_ = 0;
     return;
   }
+#elif defined(OS_FREEBSD)
+  // Disable backtrace for now, libexecinfo crashes in getframeaddr
+  // in release build / i386.
+  count_ = 0;
+  return;
 #endif
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
