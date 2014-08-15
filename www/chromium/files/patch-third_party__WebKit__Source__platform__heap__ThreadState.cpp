--- ./third_party/WebKit/Source/platform/heap/ThreadState.cpp.orig	2014-08-12 21:07:16.000000000 +0200
+++ ./third_party/WebKit/Source/platform/heap/ThreadState.cpp	2014-08-13 09:56:58.000000000 +0200
@@ -45,13 +45,22 @@
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
@@ -59,6 +68,9 @@
         pthread_attr_destroy(&attr);
         return reinterpret_cast<Address>(base) + size;
     }
+#if OS(FREEBSD)
+    pthread_attr_destroy(&attr);
+#endif
 #if defined(__GLIBC__)
     // pthread_getattr_np can fail for the main thread. In this case
     // just like NaCl we rely on the __libc_stack_end to give us
