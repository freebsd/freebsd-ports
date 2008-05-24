--- spserver/testthreadpool.cpp.orig	2008-05-24 11:47:36.000000000 +0800
+++ spserver/testthreadpool.cpp	2008-05-24 18:34:57.000000000 +0800
@@ -18,10 +18,10 @@
 
 void threadFunc( void *arg )
 {
-	int seconds = (int) arg;
+	int seconds = atoi ((char *)arg);
 
 	fprintf( stdout, "  in threadFunc %d\n", seconds );
-	fprintf( stdout, "  thread#%ld\n", sp_thread_self() );
+	fprintf( stdout, "  thread#%ld\n", (long int)sp_thread_self() );
 	sleep( seconds );
 	fprintf( stdout, "  done threadFunc %d\n", seconds);
 }
