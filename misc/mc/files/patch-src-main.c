--- src/main.c.orig	Wed Feb  5 21:54:34 2003
+++ src/main.c	Tue Jun 15 03:15:09 2004
@@ -1300,7 +1300,7 @@
 	    concat_dir_and_file (panel->cwd, selection (panel)->fname);
 	int i;
 
-	i = mc_readlink (p, buffer, MC_MAXPATHLEN);
+	i = mc_readlink (p, buffer, MC_MAXPATHLEN - 1);
 	g_free (p);
 	if (i > 0) {
 	    buffer[i] = 0;
