--- sem.c.orig	Tue Dec 13 00:33:03 2005
+++ sem.c	Tue Dec 13 00:35:22 2005
@@ -27,6 +27,7 @@
  * semaphores */
 
 #include <stdio.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ipc.h>
@@ -95,7 +96,7 @@
 	return sem;
 }
 
-static
+static void
 do_sem( sem_id, pbuf, err )
 	int sem_id;
 	struct sembuf *pbuf;
