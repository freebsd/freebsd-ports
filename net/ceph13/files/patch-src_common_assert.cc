diff --git a/src/common/assert.cc b/src/common/assert.cc
index 45d44d12ea..4a9625925f 100644
--- src/common/assert.cc
+++ src/common/assert.cc
@@ -12,6 +12,7 @@
  *
  */
 
+#include "include/compat.h"
 #include "common/debug.h"
 
 namespace ceph {
@@ -40,7 +41,7 @@ namespace ceph {
     g_assert_line = line;
     g_assert_func = func;
     g_assert_thread = (unsigned long long)pthread_self();
-    pthread_getname_np(pthread_self(), g_assert_thread_name,
+    ceph_pthread_getname(pthread_self(), g_assert_thread_name,
 		       sizeof(g_assert_thread_name));
 
     ostringstream tss;
@@ -88,7 +89,7 @@ namespace ceph {
     g_assert_line = line;
     g_assert_func = func;
     g_assert_thread = (unsigned long long)pthread_self();
-    pthread_getname_np(pthread_self(), g_assert_thread_name,
+    ceph_pthread_getname(pthread_self(), g_assert_thread_name,
 		       sizeof(g_assert_thread_name));
 
     class BufAppender {
