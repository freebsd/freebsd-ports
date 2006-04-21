--- ./talk/base/criticalsection.h.orig	Thu Mar 16 18:43:02 2006
+++ ./talk/base/criticalsection.h	Fri Apr 21 10:56:34 2006
@@ -83,8 +83,10 @@
 public:
   CriticalSection() {
     pthread_mutexattr_t mutex_attribute;
+    pthread_mutexattr_init(&mutex_attribute);
     pthread_mutexattr_settype(&mutex_attribute, PTHREAD_MUTEX_RECURSIVE);
     pthread_mutex_init(&mutex_, &mutex_attribute);
+    pthread_mutexattr_destroy(&mutex_attribute);
   }
   ~CriticalSection() {
     pthread_mutex_destroy(&mutex_);
