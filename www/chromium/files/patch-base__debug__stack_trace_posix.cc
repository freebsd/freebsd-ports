--- base/debug/stack_trace_posix.cc.orig	2012-10-01 23:40:32.000000000 +0300
+++ base/debug/stack_trace_posix.cc	2012-10-01 23:41:09.000000000 +0300
@@ -148,9 +148,15 @@
 }  // namespace
 
 StackTrace::StackTrace() {
+#if defined(OS_FREEBSD)
+  // Disable backtrace for now, libexecinfo crashes in getframeaddr
+  // in release build / i386.
+  count_ = 0;
+#else
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
   count_ = std::max(backtrace(trace_, arraysize(trace_)), 0);
+#endif
 }
 
 void StackTrace::PrintBacktrace() const {
