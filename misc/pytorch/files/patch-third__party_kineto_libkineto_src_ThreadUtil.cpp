--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2022-12-29 22:41:51 UTC
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -49,7 +49,7 @@ int32_t systemThreadId() {
 #elif defined _MSC_VER
     _sysTid = (int32_t)GetCurrentThreadId();
 #else
-    _sysTid = (int32_t)syscall(SYS_gettid);
+    _sysTid = (int32_t)syscall(SYS_getpid);
 #endif
   }
   return _sysTid;
