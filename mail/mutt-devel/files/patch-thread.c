--- thread.c.orig	Tue Jan 21 13:25:22 2003
+++ thread.c	Thu Apr 10 17:59:05 2003
@@ -1272,7 +1272,7 @@
   THREAD *threads[2];
   int i, rc;
 
-  if ((Sort & SORT_MASK) != SORT_THREADS)
+  if ((Sort & SORT_MASK) != SORT_THREADS || !hdr->thread)
     return (1);
 
   threads[0] = hdr->thread;
