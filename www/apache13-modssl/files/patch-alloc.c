RCS file: /e/apache/cvs/apache-1.3/src/main/alloc.c,v
retrieving revision 1.145
diff -u -d -r1.145 alloc.c
--- src/main/alloc.c	20 Jun 2003 15:05:40 -0000	1.145
+++ src/main/alloc.c	29 Jul 2003 19:07:46 -0000
@@ -2859,12 +2859,8 @@
 	if ((p->kill_how == kill_after_timeout)
 	    || (p->kill_how == kill_only_once)) {
 	    /* Subprocess may be dead already.  Only need the timeout if not. */
-	    if (ap_os_kill(p->pid, SIGTERM) == -1) {
-                p->kill_how = kill_never;
-            }
-            else {
-		need_timeout = 1;
-            }
+	    ap_os_kill(p->pid, SIGTERM);
+	    need_timeout = 1;
 	}
 	else if (p->kill_how == kill_always) {
 	    kill(p->pid, SIGKILL);
