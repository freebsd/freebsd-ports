--- libbitdht/src/util/bdthreads.cc.orig	2016-08-31 11:24:02 UTC
+++ libbitdht/src/util/bdthreads.cc
@@ -129,7 +129,7 @@ void bdThread::join() /* waits for the the mTid thread
 #if defined(_WIN32) || defined(__MINGW32__)
 	/* Its a struct in Windows compile and the member .p ist checked in the pthreads library */
 #else
-	if(mTid > 0)
+	if(mTid != NULL)
 #endif
 		pthread_join(mTid, NULL);
 
