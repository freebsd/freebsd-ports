
$FreeBSD$

--- util/threads/vthread-linux.cxx	2003/01/31 09:50:14	1.1
+++ util/threads/vthread-linux.cxx	2003/01/31 09:52:19
@@ -191,6 +191,12 @@
     pthread_attr_setscope(&myAttributes, PTHREAD_SCOPE_SYSTEM);
 #endif
 
+#if defined (__FreeBSD__)
+    // Default FreeBSD thread stack size (64KB) is not sufficient for the
+    // b2bua bloatware
+    pthread_attr_setstacksize (&myAttributes, 1024*1024);
+#endif
+
     // spawn the thread
     return ( pthread_create( &myId, &myAttributes, startFunc, startArgs ) );
 }
