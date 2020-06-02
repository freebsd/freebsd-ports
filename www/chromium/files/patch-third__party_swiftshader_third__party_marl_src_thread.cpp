--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2020-05-13 18:42:01 UTC
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -31,6 +31,11 @@
 #include <pthread.h>
 #include <unistd.h>
 #include <thread>
+#elif defined(__FreeBSD__)
+#include <pthread.h>
+#include <pthread_np.h>
+#include <unistd.h>
+#include <thread>
 #else
 #include <pthread.h>
 #include <unistd.h>
@@ -211,6 +216,8 @@ void Thread::setName(const char* fmt, ...) {
 
 #if defined(__APPLE__)
   pthread_setname_np(name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), name);
 #elif !defined(__Fuchsia__)
   pthread_setname_np(pthread_self(), name);
 #endif
