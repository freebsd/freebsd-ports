--- spserver/spserver.cpp.orig	2008-05-16 09:43:34.000000000 +0800
+++ spserver/spserver.cpp	2008-05-16 09:43:50.000000000 +0800
@@ -103,7 +103,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		sp_syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", thread, mPort );
+		sp_syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", (long)thread, mPort );
 	} else {
 		mIsRunning = 0;
 		sp_syslog( LOG_WARNING, "Unable to create a thread for TCP server on port [%d], %s",
