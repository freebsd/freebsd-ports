--- spserver.cpp.orig	Mon Jun 18 12:42:58 2007
+++ spserver.cpp	Mon Jun 18 12:43:52 2007
@@ -19,7 +19,7 @@
 #include "spsession.hpp"
 #include "spexecutor.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Server :: SP_Server( const char * bindIP, int port,
@@ -94,7 +94,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", thread, mPort );
+		syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", (long)thread, mPort );
 	} else {
 		mIsRunning = 0;
 		syslog( LOG_WARNING, "Unable to create a thread for TCP server on port [%d], %s",
