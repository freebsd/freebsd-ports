--- base/threading/thread_local_storage_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ base/threading/thread_local_storage_unittest.cc
@@ -90,7 +90,7 @@ class ThreadLocalStorageRunner : public DelegateSimple
 void ThreadLocalStorageCleanup(void *value) {
   int *ptr = reinterpret_cast<int*>(value);
   // Destructors should never be called with a NULL.
-  ASSERT_NE(reinterpret_cast<int*>(NULL), ptr);
+  ASSERT_NE(NULL, ptr);
   if (*ptr == kFinalTlsValue)
     return;  // We've been called enough times.
   ASSERT_LT(kFinalTlsValue, *ptr);
