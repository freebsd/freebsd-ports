--- cherokee/fdpoll-kqueue.c.orig	Fri May 27 02:42:27 2005
+++ cherokee/fdpoll-kqueue.c	Fri Sep 16 00:03:37 2005
@@ -27,6 +27,7 @@
 #include "fdpoll-protected.h"
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
 #include <unistd.h>
@@ -92,7 +93,7 @@
 		 */
 		index = fdp->nchanges;
 		if ( index > FDPOLL(fdp)->nfiles) {
-			PRINT_ERROR ("ERROR: Maximum number of fd exeeded\n");
+			PRINT_ERROR_S ("ERROR: Maximum number of fd exeeded\n");
 			return ret_error;
 		}
 		fdp->idx_fd_chlist[fd] = index;
