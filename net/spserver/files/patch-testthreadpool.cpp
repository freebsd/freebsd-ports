--- spserver/testthreadpool.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/testthreadpool.cpp	Thu Aug 23 07:34:14 2007
@@ -16,10 +16,10 @@
 
 void threadFunc( void *arg )
 {
-	int seconds = (int) arg;
+	int seconds = atoi ((char *) arg);
 
 	fprintf( stdout, "  in threadFunc %d\n", seconds );
-	fprintf( stdout, "  thread#%ld\n", pthread_self() );
+	fprintf( stdout, "  thread#%ld\n", (long int)pthread_self() );
 	sleep( seconds );
 	fprintf( stdout, "  done threadFunc %d\n", seconds);
 }
