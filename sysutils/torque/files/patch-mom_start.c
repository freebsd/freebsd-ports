--- src/resmom/freebsd5/mom_start.c.orig	Sun Oct 22 16:42:38 2006
+++ src/resmom/freebsd5/mom_start.c	Sun Oct 22 16:42:15 2006
@@ -103,7 +103,7 @@
 
 extern int	 exiting_tasks;
 extern char	 mom_host[];
-extern list_head svr_alljobs;
+extern tlist_head svr_alljobs;
 extern int	 termin_child;
 
 /* Private variables */
