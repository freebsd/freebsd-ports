--- third_party/chromium/src/base/debug/stack_trace_posix.cc.orig	2017-08-29 15:13:37 UTC
+++ third_party/chromium/src/base/debug/stack_trace_posix.cc
@@ -145,7 +145,7 @@ void ProcessBacktrace(void *const *trace
 
     handler->HandleOutput("\n");
   }
-#else
+#elif defined(OS_LINUX)
   bool printed = false;
 
   // Below part is async-signal unsafe (uses malloc), so execute it only
@@ -472,7 +472,11 @@ StackTrace::StackTrace() {
 
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
+#if defined(OS_LINUX)
   count_ = std::max(backtrace(trace_, arraysize(trace_)), 0);
+#else
+  count_ = 0;
+#endif
 }
 
 void StackTrace::Print() const {
