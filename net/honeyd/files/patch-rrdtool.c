--- rrdtool.c.orig	Thu Apr 14 16:07:26 2005
+++ rrdtool.c	Thu Apr 14 15:31:15 2005
@@ -444,7 +444,7 @@
 int
 rrdtool_fork(struct rrdtool_drv *drv)
 {
-	char *argv[3];
+	const char *argv[3];
 	int pair[2];
 	sigset_t sigmask;
 
@@ -485,7 +485,7 @@
 
 		close(pair[1]);
 
-		if (execvp(drv->bin_path, argv) == -1)
+		if (execvp(drv->bin_path, (char *const *)argv) == -1)
 			err(1, "%s: execv(%s)", __func__, drv->bin_path);
 
 		/* NOT REACHED */
