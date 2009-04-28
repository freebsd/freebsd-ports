--- media/liboggplay/src/liboggplay/std_semaphore.h.orig	2009-04-24 01:46:48.000000000 +0000
+++ media/liboggplay/src/liboggplay/std_semaphore.h	2009-04-28 08:39:25.739957779 +0000
@@ -74,7 +74,7 @@
  * @retval non-zero on error 
  */
 
-#if defined(linux) || defined(SOLARIS)
+#if defined(linux) || defined(SOLARIS) || defined(__FreeBSD__)
 #include <semaphore.h>
 #define SEM_CREATE(p,s) sem_init(&(p), 1, s)
 #define SEM_SIGNAL(p)   sem_post(&(p))
