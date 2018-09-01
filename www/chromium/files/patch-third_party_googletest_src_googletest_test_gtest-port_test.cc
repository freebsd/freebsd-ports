--- third_party/googletest/src/googletest/test/gtest-port_test.cc.orig	2018-08-23 02:48:03.607358000 +0200
+++ third_party/googletest/src/googletest/test/gtest-port_test.cc	2018-08-23 02:48:57.198397000 +0200
@@ -296,7 +296,8 @@
   EXPECT_EQ("unknown file", FormatCompilerIndependentFileLocation(NULL, -1));
 }
 
-#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA
+#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA || \
+    GTEST_OS_FREEBSD
 void* ThreadFunc(void* data) {
   internal::Mutex* mutex = static_cast<internal::Mutex*>(data);
   mutex->Lock();
