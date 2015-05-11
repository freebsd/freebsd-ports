--- osquery/dispatcher/tests/dispatcher_tests.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/dispatcher/tests/dispatcher_tests.cpp
@@ -28,7 +28,7 @@ class TestRunnable : public InternalRunn
  public:
   int* i;
   explicit TestRunnable(int* i) : i(i) {}
-  virtual void enter() { ++*i; }
+  virtual void start() { ++*i; }
 };
 
 TEST_F(DispatcherTests, test_add_work) {
