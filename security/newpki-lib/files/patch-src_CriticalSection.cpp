--- src/CriticalSection.cpp.orig	Tue Jul  5 03:01:18 2005
+++ src/CriticalSection.cpp	Tue Jul  5 03:01:33 2005
@@ -43,7 +43,7 @@
 		assert(hMutex != NULL);
 	#else
 		pthread_mutexattr_init(&recmutex);
-		pthread_mutexattr_settype(&recmutex, PTHREAD_MUTEX_RECURSIVE_NP);
+		pthread_mutexattr_settype(&recmutex, PTHREAD_MUTEX_RECURSIVE);
 		pthread_mutex_init(&lpCriticalSection, &recmutex);
 	#endif
 	#ifdef _DEBUG
