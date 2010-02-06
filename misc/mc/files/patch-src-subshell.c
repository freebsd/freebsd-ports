--- src/subshell.c.orig	2010-02-06 15:34:55.000000000 +0600
+++ src/subshell.c	2010-02-06 15:35:52.000000000 +0600
@@ -948,7 +948,7 @@
     wptr = fail_on_error ? &wtime : NULL;
 
     while (1) {
-	if (!subshell_alive)
+	if (!subshell_alive || !pty_buffer)
 	    return FALSE;
 
 	/* Prepare the file-descriptor set and call `select' */
