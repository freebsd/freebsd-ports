--- gui2/gretl.c.orig	Tue Oct  8 02:10:30 2002
+++ gui2/gretl.c	Mon Oct 21 08:48:34 2002
@@ -1560,7 +1560,7 @@
 {
     pid_t pid;
 
-    signal(SIGCLD, SIG_IGN);
+    signal(SIGCHLD, SIG_IGN);
 
     pid = fork();
     if (pid == -1) {
@@ -1649,7 +1649,7 @@
 	return;
     }
 
-    signal(SIGCLD, SIG_IGN); 
+    signal(SIGCHLD, SIG_IGN); 
     pid = fork();
 
     if (pid == -1) {
