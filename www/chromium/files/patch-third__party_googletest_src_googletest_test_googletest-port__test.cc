--- third_party/googletest/src/googletest/test/googletest-port-test.cc.orig	2018-12-15 18:52:24.209622000 +0100
+++ third_party/googletest/src/googletest/test/googletest-port-test.cc	2018-12-15 18:53:04.599624000 +0100
@@ -293,7 +293,7 @@
   EXPECT_EQ("unknown file", FormatCompilerIndependentFileLocation(NULL, -1));
 }
 
-#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA
+#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA || GTEST_OS_FREEBSD
 void* ThreadFunc(void* data) {
   internal::Mutex* mutex = static_cast<internal::Mutex*>(data);
   mutex->Lock();
