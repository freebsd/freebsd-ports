--- spserver/spthreadpool.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/spthreadpool.cpp	Thu Aug 23 07:33:50 2007
@@ -120,7 +120,7 @@
 
 		if( 0 == pthread_create( &( thread->mId ), &attr, wrapperFunc, thread ) ) {
 			mTotal++;
-			syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, thread->mId );
+			syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, (long)thread->mId );
 		} else {
 			ret = -1;
 			syslog( LOG_WARNING, "[tp@%s] cannot create thread\n", mTag );
