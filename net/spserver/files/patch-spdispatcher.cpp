--- spserver/spdispatcher.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/spdispatcher.cpp	Thu Aug 23 07:33:12 2007
@@ -23,7 +23,7 @@
 #include "spiochannel.hpp"
 #include "spioutils.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Dispatcher :: SP_Dispatcher( SP_CompletionHandler * completionHandler, int maxThreads )
@@ -95,7 +95,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", thread );
+		syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", (long) thread );
 	} else {
 		mIsRunning = 0;
 		syslog( LOG_WARNING, "Unable to create a thread for dispatcher, %s",
