--- talk/base/thread.cc.orig	2008-09-06 23:02:42.000000000 -0300
+++ talk/base/thread.cc	2008-09-06 23:03:04.000000000 -0300
@@ -122,6 +122,7 @@
     pthread_attr_setschedparam(&attr, &param);
   }
   pthread_create(&thread_, &attr, PreRun, this);
+  pthread_attr_destroy(&attr);
   started_ = true;
 }
 
