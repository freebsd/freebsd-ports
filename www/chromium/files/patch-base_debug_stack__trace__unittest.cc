--- base/debug/stack_trace_unittest.cc.orig	2020-11-13 06:36:34 UTC
+++ base/debug/stack_trace_unittest.cc
@@ -88,6 +88,7 @@ TEST_F(StackTraceTest, OutputToStream) {
             std::string::npos)
       << "Unable to resolve symbols.";
 
+#if !defined(OS_BSD)
   // Expect a demangled symbol.
   // Note that Windows Release builds omit the function parameters from the
   // demangled stack output, otherwise this could be "testing::UnitTest::Run()".
@@ -106,9 +107,10 @@ TEST_F(StackTraceTest, OutputToStream) {
   EXPECT_TRUE(backtrace_message.find(__func__) != std::string::npos)
       << "Expected to find " << __func__ << " in backtrace:\n"
       << backtrace_message;
+#endif
 }
 
-#if !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES)
+#if !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES) && !defined(OS_BSD)
 // Disabled in Official builds, where Link-Time Optimization can result in two
 // or fewer stack frames being available, causing the test to fail.
 TEST_F(StackTraceTest, TruncatedTrace) {
@@ -122,7 +124,7 @@ TEST_F(StackTraceTest, TruncatedTrace) {
   truncated.Addresses(&count);
   EXPECT_EQ(2u, count);
 }
-#endif  // !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES)
+#endif  // !defined(OFFICIAL_BUILD) && !defined(NO_UNWIND_TABLES) && !defined(OS_BSD)
 
 // The test is used for manual testing, e.g., to see the raw output.
 TEST_F(StackTraceTest, DebugOutputToStream) {
