--- testthreadpool.cpp.orig	2007-08-09 17:14:03.000000000 +0800
+++ testthreadpool.cpp	2007-08-09 17:15:20.000000000 +0800
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
