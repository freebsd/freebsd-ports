--- sys_curses/system.c.orig	Tue Jun  4 21:54:07 2002
+++ sys_curses/system.c	Tue Jun  4 21:54:27 2002
@@ -588,10 +588,10 @@
 static void
 child_died(code)
 {
-    union wait status;
+    int status;
     register int pid;
 
-    while ((pid = wait3((int *)&status, WNOHANG, (struct rusage *)0)) > 0) {
+    while ((pid = wait3(&status, WNOHANG, (struct rusage *)0)) > 0) {
 	if (pid == shell_pid) {
 	    int ch;
 	    extern void setconnmode();
