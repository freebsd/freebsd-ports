--- third_party/chromium/src/base/debug/stack_trace_posix.cc.org	2012-03-31 16:29:07.080777000 +0900
+++ third_party/chromium/src/base/debug/stack_trace_posix.cc	2012-03-31 17:00:32.436774287 +0900
@@ -127,7 +127,7 @@
       trace_strings->push_back(base::StringPrintf("%p", trace[i]));
     }
   }
-#else
+#elif defined(OS_LINUX)
   scoped_ptr_malloc<char*> trace_symbols(backtrace_symbols(trace, size));
   if (trace_symbols.get()) {
     for (int i = 0; i < size; ++i) {
@@ -156,10 +156,13 @@
     count_ = 0;
     return;
   }
-#endif
+#elif defined(OS_LINUX)
   // Though the backtrace API man page does not list any possible negative
   // return values, we take no chance.
   count_ = std::max(backtrace(trace_, arraysize(trace_)), 0);
+#else
+  count_ = 0;
+#endif
 }
 
 void StackTrace::PrintBacktrace() const {
