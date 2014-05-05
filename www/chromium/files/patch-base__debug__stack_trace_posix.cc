--- ./base/debug/stack_trace_posix.cc.orig	2014-04-24 22:36:11.000000000 +0200
+++ ./base/debug/stack_trace_posix.cc	2014-04-24 23:23:41.000000000 +0200
@@ -471,7 +471,7 @@
 
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
-  count_ = std::max(backtrace(trace_, arraysize(trace_)), 0);
+  count_ = std::max<size_t>(backtrace(trace_, arraysize(trace_)), 0);
 }
 
 void StackTrace::Print() const {
