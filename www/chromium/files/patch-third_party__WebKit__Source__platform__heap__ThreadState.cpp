--- third_party/WebKit/Source/platform/heap/ThreadState.cpp.orig	2014-10-02 18:00:37 UTC
+++ third_party/WebKit/Source/platform/heap/ThreadState.cpp
@@ -54,13 +54,22 @@
 #include <sanitizer/msan_interface.h>
 #endif
 
+#if OS(FREEBSD)
+#include <pthread_np.h>
+#endif
+
 namespace blink {
 
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
@@ -68,6 +77,9 @@
         pthread_attr_destroy(&attr);
         return reinterpret_cast<Address>(base) + size;
     }
+#if OS(FREEBSD)
+	pthread_attr_destroy(&attr);
+#endif
 #if defined(__GLIBC__)
     // pthread_getattr_np can fail for the main thread. In this case
     // just like NaCl we rely on the __libc_stack_end to give us
