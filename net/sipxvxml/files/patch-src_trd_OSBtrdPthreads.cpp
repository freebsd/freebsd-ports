--- ./src/trd/OSBtrdPthreads.cpp.orig	Fri Dec 29 10:46:31 2006
+++ ./src/trd/OSBtrdPthreads.cpp	Fri Dec 29 10:48:57 2006
@@ -497,7 +497,7 @@
   if (thread == NULL) 
 	return -1;
 
-  return thread->thread;
+  return (VXIlong)thread->thread;
 }
 
 
