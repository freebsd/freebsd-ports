--- spserver/spexecutor.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/spexecutor.cpp	Thu Aug 23 07:33:20 2007
@@ -14,7 +14,7 @@
 #include "spexecutor.hpp"
 #include "spthreadpool.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Task :: ~SP_Task()
@@ -67,7 +67,7 @@
 	int ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, thread );
+		syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, (long)thread );
 	} else {
 		syslog( LOG_WARNING, "[ex@%s] Unable to create a thread for executor", tag );
 	}
