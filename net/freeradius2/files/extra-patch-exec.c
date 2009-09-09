--- src/main/exec.c	2008-12-05 11:37:56.000000000 -0500
+++ src/main/exec.c	2009-01-18 17:43:32.000000000 -0500
@@ -222,6 +222,8 @@
 		output_pairs = NULL;
 	}

+	signal(SIGCHLD, SIG_DFL);
+
 	if (exec_wait) {
 		pid = rad_fork();	/* remember PID */
 	} else {
