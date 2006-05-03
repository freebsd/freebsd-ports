--- talk/base/thread.cc.orig	Tue May  2 11:43:09 2006
+++ talk/base/thread.cc	Tue May  2 11:43:21 2006
@@ -113,6 +113,7 @@
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_create(&thread_, &attr, PreLoop, this);
+  pthread_attr_destroy(&attr);
   started_ = true;
 }
 
