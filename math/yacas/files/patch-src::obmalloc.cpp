--- src/obmalloc.cpp	2002/11/24 17:48:08	1.5
+++ src/obmalloc.cpp	2004/07/03 19:32:15	1.6
@@ -318,7 +318,7 @@
 /*
  * This malloc lock
  */
-SIMPLELOCK_DECL(_malloc_lock);
+SIMPLELOCK_DECL(_malloc_lock)
 #define LOCK()		SIMPLELOCK_LOCK(_malloc_lock)
 #define UNLOCK()	SIMPLELOCK_UNLOCK(_malloc_lock)
 #define LOCK_INIT()	SIMPLELOCK_INIT(_malloc_lock)
