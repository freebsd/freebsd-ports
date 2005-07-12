--- cherokee/fdpoll-kqueue.c.orig	Fri May 27 02:42:27 2005
+++ cherokee/fdpoll-kqueue.c	Mon Jul 11 15:41:35 2005
@@ -92,7 +92,7 @@
 		 */
 		index = fdp->nchanges;
 		if ( index > FDPOLL(fdp)->nfiles) {
-			PRINT_ERROR ("ERROR: Maximum number of fd exeeded\n");
+			PRINT_ERROR_S ("ERROR: Maximum number of fd exeeded\n");
 			return ret_error;
 		}
 		fdp->idx_fd_chlist[fd] = index;
