--- third_party/googletest/src/googletest/test/googletest-port-test.cc.orig	2019-03-11 22:08:00 UTC
+++ third_party/googletest/src/googletest/test/googletest-port-test.cc
@@ -286,7 +286,7 @@ TEST(FormatCompilerIndependentFileLocationTest, Format
   EXPECT_EQ("unknown file", FormatCompilerIndependentFileLocation(nullptr, -1));
 }
 
-#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA
+#if GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_QNX || GTEST_OS_FUCHSIA || GTEST_OS_FREEBSD
 void* ThreadFunc(void* data) {
   internal::Mutex* mutex = static_cast<internal::Mutex*>(data);
   mutex->Lock();
