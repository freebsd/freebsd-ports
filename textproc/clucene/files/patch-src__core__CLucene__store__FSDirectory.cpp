--- src/core/CLucene/store/FSDirectory.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/store/FSDirectory.cpp	2014-06-24 18:26:54.000000000 -0400
@@ -219,9 +219,8 @@
 		_CLDECDELETE(handle);
 
 		//printf("handle=%d\n", handle->__cl_refcount);
-		if ( dounlock ){
-			mutex->unlock();
-		}else{
+		mutex->unlock();
+		if ( !dounlock ) {
 			delete mutex;
 		}
 	}
