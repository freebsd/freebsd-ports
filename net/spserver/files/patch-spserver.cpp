--- spserver/spserver.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/spserver.cpp	Thu Aug 23 07:33:42 2007
@@ -22,7 +22,7 @@
 #include "spiochannel.hpp"
 #include "spioutils.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Server :: SP_Server( const char * bindIP, int port,
@@ -106,7 +106,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", thread, mPort );
+		syslog( LOG_NOTICE, "Thread #%ld has been created to listen on port [%d]", (long)thread, mPort );
 	} else {
 		mIsRunning = 0;
 		syslog( LOG_WARNING, "Unable to create a thread for TCP server on port [%d], %s",
