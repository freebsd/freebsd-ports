--- chrome/test/perf/perf_test.cc.orig	2013-08-19 21:01:58.000000000 +0300
+++ chrome/test/perf/perf_test.cc	2013-08-19 21:03:16.000000000 +0300
@@ -352,7 +352,7 @@
   AppendResult(output, "ws_final_t", "", "ws_f_t" + trace_name,
                total_working_set_size, "bytes",
                false /* not important */);
-#elif defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_NACL)
   AppendResult(output,
                "vm_size_final_b",
                std::string(),
