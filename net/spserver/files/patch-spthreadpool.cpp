--- spserver/spthreadpool.cpp.orig	2011-06-21 08:59:54.000000000 +0800
+++ spserver/spthreadpool.cpp	2011-06-21 09:00:06.000000000 +0800
@@ -122,7 +122,7 @@ int SP_ThreadPool :: dispatch( DispatchF
 
 		if( 0 == sp_thread_create( &( thread->mId ), &attr, wrapperFunc, thread ) ) {
 			mTotal++;
-			sp_syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, thread->mId );
+			sp_syslog( LOG_NOTICE, "[tp@%s] create thread#%ld\n", mTag, (long)thread->mId );
 		} else {
 			ret = -1;
 			sp_syslog( LOG_WARNING, "[tp@%s] cannot create thread\n", mTag );
