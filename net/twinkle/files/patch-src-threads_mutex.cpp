--- src/threads/mutex.cpp	Sat Apr 22 21:09:20 2006
+++ src/threads/mutex.cpp	Sat Apr 22 21:08:41 2006
@@ -35,7 +35,7 @@
 	pthread_mutexattr_init(&attr);
 
 
-	int ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+	int ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 	if (ret != 0) throw string(
 		"t_mutex::t_mutex failed to create a recursive mutex.");
 
