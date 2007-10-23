--- gpsmap.cc.orig	Mon Oct 15 15:13:32 2007
+++ gpsmap.cc	Mon Oct 15 15:15:19 2007
@@ -2242,11 +2242,11 @@
     pthread_attr_destroy(&attr);
 
     // Now wait for the threads to complete and come back
-    int thread_status;
+    intptr_t thread_status;
     for (int t = 0; t < numthreads; t++) {
         void *tmp;
         pthread_join(mapthread[t], &tmp);
-	thread_status = reinterpret_cast<int>(tmp);
+	thread_status = reinterpret_cast<intptr_t>(tmp);
     }
 #else
     // Run one instance of our "thread".  thread number 0, it should just crunch it all
