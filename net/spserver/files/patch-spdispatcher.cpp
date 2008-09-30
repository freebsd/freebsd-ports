--- spserver/spdispatcher.cpp.orig	2008-09-03 22:12:05.000000000 +0800
+++ spserver/spdispatcher.cpp	2008-09-25 05:41:53.000000000 +0800
@@ -97,7 +97,7 @@
 	ret = sp_thread_create( &thread, &attr, eventLoop, this );
 	sp_thread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		sp_syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", thread );
+		sp_syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", (long)thread );
 	} else {
 		mIsRunning = 0;
 		sp_syslog( LOG_WARNING, "Unable to create a thread for dispatcher, %s",
