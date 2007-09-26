--- innfeed/endpoint.c.orig	Mon Mar 20 04:14:57 2006
+++ innfeed/endpoint.c	Wed Sep 26 20:02:26 2007
@@ -1644,7 +1644,7 @@
   if (sigHandlers == NULL)
     {
       sigHandlers = xmalloc (sizeof(sigfn) * NSIG) ;
-      sigFlags = xmalloc (sizeof(int) * NSIG) ;
+      sigFlags = xmalloc (sizeof(sig_atomic_t) * NSIG) ;
       for (i = 0 ; i < NSIG ; i++)
         {
           sigHandlers [i] = NULL ;
