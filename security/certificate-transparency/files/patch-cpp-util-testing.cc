--- cpp/util/testing.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/util/testing.cc
@@ -3,6 +3,9 @@
 #include <event2/thread.h>
 #include <evhtp.h>
 #include <glog/logging.h>
+// Without this, build will fail due to clash between onigposix.h
+// and regex.h.
+#define GTEST_HAS_POSIX_RE 0
 #include <gtest/gtest.h>
 
 #include "config.h"
@@ -15,7 +18,7 @@ namespace test {
 void InitTesting(const char* name, int* argc, char*** argv,
                  bool remove_flags) {
   ::testing::InitGoogleTest(argc, *argv);
-  google::ParseCommandLineFlags(argc, argv, remove_flags);
+  gflags::ParseCommandLineFlags(argc, argv, remove_flags);
   google::InitGoogleLogging(name);
   google::InstallFailureSignalHandler();
   evthread_use_pthreads();
