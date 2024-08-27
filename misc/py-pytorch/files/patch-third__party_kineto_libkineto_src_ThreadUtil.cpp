--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2024-07-24 18:41:37 UTC
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -59,7 +59,7 @@ int32_t systemThreadId() {
 #elif defined __FreeBSD__
     syscall(SYS_thr_self, &_sysTid);
 #else
-    _sysTid = (int32_t)syscall(SYS_gettid);
+    _sysTid = (int32_t)syscall(SYS_getpid);
 #endif
   }
   return _sysTid;
