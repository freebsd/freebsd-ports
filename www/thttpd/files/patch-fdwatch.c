--- fdwatch.c.orig	Fri Aug 24 00:19:39 2001
+++ fdwatch.c	Fri Aug 24 00:20:30 2001
@@ -311,6 +311,9 @@
     if ( kqchanges == (struct kevent*) 0 || kqevents == (struct kevent*) 0 ||
 	 kqrfdidx == (int*) 0 )
 	return -1;
+    memset(kqchanges, '\0', sizeof(struct kevent) * 2 * nfiles);
+    memset(kqevents, '\0', sizeof(struct kevent) * nfiles);
+    memset(kqrfdidx, '\0', sizeof(int) * nfiles);
     return 0;
     }
 
