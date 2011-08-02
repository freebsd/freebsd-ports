--- third_party/leveldb/util/env_chromium.cc.orig	2011-06-27 01:35:45.210558183 +0300
+++ third_party/leveldb/util/env_chromium.cc	2011-06-27 01:44:12.434784726 +0300
@@ -29,7 +29,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_WIN)
+#if !defined(OS_LINUX)
 // The following are glibc-specific
 namespace {
 
@@ -420,7 +420,7 @@
 #elif defined(OS_FREEBSD) || defined(OS_NACL)
     // TODO(BSD): find a better thread ID
     pthread_t tid = pthread_self();
-    memcpy(&thread_id, &tid, min(sizeof(r), sizeof(tid)));
+    memcpy(&thread_id, &tid, std::min(sizeof(thread_id), sizeof(tid)));
 #endif
 
     // We try twice: the first time with a fixed-size stack allocated buffer,
