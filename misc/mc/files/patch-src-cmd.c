--- src/cmd.c.orig	Wed Feb  5 21:54:33 2003
+++ src/cmd.c	Tue Jun 15 03:15:09 2004
@@ -1132,7 +1132,7 @@
 
 	q = g_strdup_printf (_(" Symlink `%s\' points to: "), name_trunc (p, 32));
 
-	i = readlink (p, buffer, MC_MAXPATHLEN);
+	i = readlink (p, buffer, MC_MAXPATHLEN - 1);
 	if (i > 0) {
 	    buffer [i] = 0;
 	    dest = input_expand_dialog (_(" Edit symlink "), q, buffer);
