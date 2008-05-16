--- spserver/spexecutor.cpp.orig	2008-05-16 09:42:34.000000000 +0800
+++ spserver/spexecutor.cpp	2008-05-16 09:42:57.000000000 +0800
@@ -64,7 +64,7 @@
 	int ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		sp_syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, thread );
+		sp_syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, (long)thread );
 	} else {
 		sp_syslog( LOG_WARNING, "[ex@%s] Unable to create a thread for executor", tag );
 	}
