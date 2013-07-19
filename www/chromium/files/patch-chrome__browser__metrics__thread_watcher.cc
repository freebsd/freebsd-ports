--- chrome/browser/metrics/thread_watcher.cc	2013-07-03 23:45:55.000000000 -0400
+++ chrome/browser/metrics/thread_watcher.cc	2013-07-19 01:38:45.000000000 -0400
@@ -40,7 +40,7 @@
 MSVC_PUSH_DISABLE_WARNING(4748)
 
 int* NullPointer() {
-  return reinterpret_cast<int*>(NULL);
+  return static_cast<int*>(0);
 }
 
 void NullPointerCrash(int line_number) {
