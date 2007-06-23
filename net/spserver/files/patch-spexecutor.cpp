--- spexecutor.cpp.orig	Mon Jun 11 15:20:34 2007
+++ spexecutor.cpp	Mon Jun 18 12:44:56 2007
@@ -14,7 +14,7 @@
 #include "spexecutor.hpp"
 #include "spthreadpool.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_Task :: ~SP_Task()
@@ -83,7 +83,7 @@
 	int ret = pthread_create( &thread, &attr, reinterpret_cast<void*(*)(void*)>(eventLoop), this );
 	pthread_attr_destroy( &attr );
 	if( 0 == ret ) {
-		syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, thread );
+		syslog( LOG_NOTICE, "[ex@%s] Thread #%ld has been created for executor", tag, (long)thread );
 	} else {
 		syslog( LOG_WARNING, "[ex@%s] Unable to create a thread for executor", tag );
 	}
