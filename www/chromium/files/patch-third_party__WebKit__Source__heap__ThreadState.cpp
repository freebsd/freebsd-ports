--- ./third_party/WebKit/Source/heap/ThreadState.cpp.orig	2014-04-24 22:39:56.000000000 +0200
+++ ./third_party/WebKit/Source/heap/ThreadState.cpp	2014-04-24 23:23:47.000000000 +0200
@@ -43,13 +43,22 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
 namespace WebCore {
 
 static void* getStackStart()
 {
-#if defined(__GLIBC__) || OS(ANDROID)
+#if defined(__GLIBC__) || OS(ANDROID) || OS(FREEBSD)
     pthread_attr_t attr;
+#if OS(FREEBSD)
+    pthread_attr_init(&attr);
+    if (!pthread_attr_get_np(pthread_self(), &attr)) {
+#else
     if (!pthread_getattr_np(pthread_self(), &attr)) {
+#endif
         void* base;
         size_t size;
         int error = pthread_attr_getstack(&attr, &base, &size);
@@ -57,6 +66,9 @@
         pthread_attr_destroy(&attr);
         return reinterpret_cast<Address>(base) + size;
     }
+#if OS(FREEBSD)
+    pthread_attr_destroy(&attr);
+#endif
 #if defined(__GLIBC__)
     // pthread_getattr_np can fail for the main thread. In this case
     // just like NaCl we rely on the __libc_stack_end to give us
