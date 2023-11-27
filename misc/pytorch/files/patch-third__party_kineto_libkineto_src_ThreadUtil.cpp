--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2023-04-03 19:46:02 UTC
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -57,7 +57,7 @@ int32_t systemThreadId() {
 #elif defined _MSC_VER
     _sysTid = (int32_t)GetCurrentThreadId();
 #else
-    _sysTid = (int32_t)syscall(SYS_gettid);
+    _sysTid = (int32_t)syscall(SYS_getpid);
 #endif
   }
   return _sysTid;
