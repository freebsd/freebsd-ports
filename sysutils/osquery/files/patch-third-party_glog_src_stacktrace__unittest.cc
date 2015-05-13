--- third-party/glog/src/stacktrace_unittest.cc.orig	2015-05-05 12:29:29 UTC
+++ third-party/glog/src/stacktrace_unittest.cc
@@ -125,16 +125,6 @@ void ATTRIBUTE_NOINLINE CheckStackTraceL
   CHECK_GE(size, 1);
   CHECK_LE(size, STACK_LEN);
 
-  if (1) {
-#ifdef HAVE_EXECINFO_H
-    char **strings = backtrace_symbols(stack, size);
-    printf("Obtained %d stack frames.\n", size);
-    for (int i = 0; i < size; i++)
-      printf("%s %p\n", strings[i], stack[i]);
-    printf("CheckStackTrace() addr: %p\n", &CheckStackTrace);
-    free(strings);
-#endif
-  }
   for (int i = 0; i < BACKTRACE_STEPS; i++) {
     printf("Backtrace %d: expected: %p..%p  actual: %p ... ",
            i, expected_range[i].start, expected_range[i].end, stack[i]);
