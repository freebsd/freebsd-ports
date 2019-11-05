--- third_party/swiftshader/src/Yarn/Thread.cpp.orig	2019-10-30 22:22:11 UTC
+++ third_party/swiftshader/src/Yarn/Thread.cpp
@@ -27,6 +27,10 @@
 #   include <pthread.h>
 #   include <mach/thread_act.h>
 #   include <unistd.h>
+#elif defined(__FreeBSD__)
+#   include <pthread.h>
+#   include <pthread_np.h>
+#   include <unistd.h>
 #else
 #   include <pthread.h>
 #   include <unistd.h>
@@ -88,6 +92,8 @@ void Thread::setName(const char* fmt, ...)
 
 #if defined(__APPLE__)
     pthread_setname_np(name);
+#elif defined(__FreeBSD__)
+    pthread_set_name_np(pthread_self(), name);
 #elif !defined(__Fuchsia__)
     pthread_setname_np(pthread_self(), name);
 #endif
