Index: src/main/alloc.c
===================================================================
RCS file: /home/cvs/apache-1.3/src/main/alloc.c,v
retrieving revision 1.145
retrieving revision 1.146
diff -u -r1.145 -r1.146
--- src/main/alloc.c	20 Jun 2003 15:05:40 -0000	1.145
+++ src/main/alloc.c	2 Sep 2003 18:17:05 -0000	1.146
@@ -2859,12 +2859,10 @@
 	if ((p->kill_how == kill_after_timeout)
 	    || (p->kill_how == kill_only_once)) {
 	    /* Subprocess may be dead already.  Only need the timeout if not. */
-	    if (ap_os_kill(p->pid, SIGTERM) == -1) {
-                p->kill_how = kill_never;
-            }
-            else {
-		need_timeout = 1;
-            }
+	    if ( (ap_os_kill(p->pid, SIGTERM) == -1) && (errno == ESRCH) )
+	        p->kill_how = kill_never;
+	    else
+	        need_timeout = 1;
 	}
 	else if (p->kill_how == kill_always) {
 	    kill(p->pid, SIGKILL);
