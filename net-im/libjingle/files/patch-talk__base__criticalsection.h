--- talk/base/criticalsection.h.orig	Wed Feb 22 18:57:24 2006
+++ talk/base/criticalsection.h	Wed Feb 22 18:54:37 2006
@@ -83,6 +83,7 @@
 public:
   CriticalSection() {
     pthread_mutexattr_t mutex_attribute;
+    pthread_mutexattr_init(&mutex_attribute);
     pthread_mutexattr_settype(&mutex_attribute, PTHREAD_MUTEX_RECURSIVE);
     pthread_mutex_init(&mutex_, &mutex_attribute);
   }
