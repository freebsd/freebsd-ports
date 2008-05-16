--- spserver/spdispatcher.cpp.orig	2008-04-19 20:33:45.000000000 +0800
+++ spserver/spdispatcher.cpp	2008-05-16 09:40:51.000000000 +0800
@@ -96,7 +96,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		sp_syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", thread );
+		sp_syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", (long)thread );
 	} else {
 		mIsRunning = 0;
 		sp_syslog( LOG_WARNING, "Unable to create a thread for dispatcher, %s",
