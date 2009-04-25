--- media/liboggplay/src/liboggplay/std_semaphore.h.orig	2009-03-05 22:32:15.000000000 +0100
+++ media/liboggplay/src/liboggplay/std_semaphore.h	2009-04-10 12:31:04.000000000 +0200
@@ -34,7 +34,7 @@
 
 #ifndef _STD_SEMAPHORE_H
 #define _STD_SEMAPHORE_H
-#if defined(linux) || defined(SOLARIS)
+#if defined(linux) || defined(SOLARIS) || defined(__FreeBSD__)
 #include <semaphore.h>
 #define SEM_CREATE(p,s) sem_init(&(p), 1, s)
 #define SEM_SIGNAL(p)   sem_post(&(p))
