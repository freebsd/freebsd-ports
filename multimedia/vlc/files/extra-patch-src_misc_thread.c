--- src/misc/threads.c.orig	2009-08-01 09:34:56.000000000 -0400
+++ src/misc/threads.c	2009-08-01 09:40:24.000000000 -0400
@@ -784,7 +784,7 @@
         pthread_sigmask (SIG_BLOCK, &set, &oldset);
     }
 
-#if defined (_POSIX_PRIORITY_SCHEDULING) && (_POSIX_PRIORITY_SCHEDULING >= 0) \
+#if 0 && defined (_POSIX_PRIORITY_SCHEDULING) && (_POSIX_PRIORITY_SCHEDULING >= 0) \
  && defined (_POSIX_THREAD_PRIORITY_SCHEDULING) \
  && (_POSIX_THREAD_PRIORITY_SCHEDULING >= 0)
     {
