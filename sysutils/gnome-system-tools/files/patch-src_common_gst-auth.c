--- src/common/gst-auth.c.orig	Thu Mar 10 14:39:18 2005
+++ src/common/gst-auth.c	Thu Mar 10 14:39:50 2005
@@ -142,12 +142,12 @@ gst_auth_run_term (GstTool *tool, gchar 
 		unsetenv("LANG");
 		unsetenv("LANGUAGE");
 
-		dup2 (p[1], 1);
-		dup2 (p[1], 2);
+		dup2 (p[1], STDOUT_FILENO);
+		/*dup2 (p[1], 2);*/
 		close (p[0]);
 
 		execv (args[0], args);
-		exit (255);
+		_exit (255);
 	} else {
 #ifndef __FreeBSD__
 		/* Linux's su works ok with echo disabling */
