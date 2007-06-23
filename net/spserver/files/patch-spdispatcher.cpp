--- spdispatcher.cpp.orig	Sat Jun 23 20:21:18 2007
+++ spdispatcher.cpp	Sat Jun 23 20:21:40 2007
@@ -20,7 +20,7 @@
 #include "spsession.hpp"
 #include "spexecutor.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Dispatcher :: SP_Dispatcher( SP_CompletionHandler * completionHandler, int maxThreads )
@@ -110,7 +110,7 @@
 	ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", thread );
+		syslog( LOG_NOTICE, "Thread #%ld has been created for dispatcher", (long) thread );
 	} else {
 		mIsRunning = 0;
 		syslog( LOG_WARNING, "Unable to create a thread for dispatcher, %s",
