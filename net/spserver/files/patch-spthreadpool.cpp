--- spthreadpool.cpp.orig	Mon Jun 18 12:38:42 2007
+++ spthreadpool.cpp	Mon Jun 18 12:39:00 2007
@@ -119,7 +119,7 @@
 
 		if( 0 == pthread_create( &( thread->mId ), &attr, wrapperFunc, thread ) ) {
 			mTotal++;
-			syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, thread->mId );
+			syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, (long)thread->mId );
 		} else {
 			ret = -1;
 			syslog( LOG_WARNING, "[tp@%s] cannot create thread\n", mTag );
