--- base/test/test_suite.cc.orig	2022-01-05 13:32:44 UTC
+++ base/test/test_suite.cc
@@ -221,7 +221,7 @@ class CheckForLeakedGlobals : public testing::EmptyTes
 };
 
 // base::Process is not available on iOS
-#if !defined(OS_IOS)
+#if !defined(OS_IOS) && !defined(OS_BSD)
 class CheckProcessPriority : public testing::EmptyTestEventListener {
  public:
   CheckProcessPriority() { CHECK(!IsProcessBackgrounded()); }
@@ -634,7 +634,7 @@ void TestSuite::Initialize() {
   if (check_for_leaked_globals_)
     listeners.Append(new CheckForLeakedGlobals);
   if (check_for_thread_and_process_priority_) {
-#if !defined(OS_IOS)
+#if !defined(OS_IOS) && !defined(OS_BSD)
     listeners.Append(new CheckProcessPriority);
 #endif
   }
