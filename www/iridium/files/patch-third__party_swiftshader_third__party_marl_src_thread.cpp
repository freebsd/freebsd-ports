--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2019-12-22 15:09:09 UTC
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -27,6 +27,10 @@
 #include <mach/thread_act.h>
 #include <pthread.h>
 #include <unistd.h>
+#elif defined(__FreeBSD__)
+#include <pthread.h>
+#include <pthread_np.h>
+#include <unistd.h>
 #else
 #include <pthread.h>
 #include <unistd.h>
@@ -85,6 +89,8 @@ void Thread::setName(const char* fmt, ...) {
 
 #if defined(__APPLE__)
   pthread_setname_np(name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), name);
 #elif !defined(__Fuchsia__)
   pthread_setname_np(pthread_self(), name);
 #endif
