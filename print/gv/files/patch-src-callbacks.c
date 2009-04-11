--- src/callbacks.c.orig	2009-04-10 00:01:22.379498762 -0400
+++ src/callbacks.c	2009-04-10 00:02:32.330844813 -0400
@@ -957,7 +957,7 @@
     
     BEGINMESSAGE(cb_presentation)
 
-    sigold = signal(SIGCLD, SIG_IGN); /* Avoid zombies */
+    sigold = signal(SIGCHLD, SIG_IGN); /* Avoid zombies */
     if (!(pid = fork()))
     {
        /* We have to close all open file descriptors so the child does not
@@ -969,7 +969,7 @@
        printf("Cannot exec %s\n", gv_bin);
        exit(1);
     }
-    signal(SIGCLD, sigold); /* restore signal handler */
+    signal(SIGCHLD, sigold); /* restore signal handler */
     
     ENDMESSAGE(cb_presentation)
 }
