--- src/main.c.orig	Fri Apr 26 14:29:08 2002
+++ src/main.c	Fri Apr 26 14:52:43 2002
@@ -394,7 +394,12 @@
 	for (i = 0; i < n; i++)
 	{
 		/* try to expand as files */
-		if (realpath (args[i], buffer) != NULL)
+		if (strncmp(args[i], "ghelp:", strlen("ghelp:")) &&
+		    strncmp(args[i], "toc:", strlen("toc:")) &&
+		    strncmp(args[i], "info:", strlen("info:")) &&
+		    strncmp(args[i], "main:", strlen("man:")) &&
+		    strncmp(args[i], "gnome-help:", strlen("gnome-help")) &&
+		    realpath (args[i], buffer) != NULL)
 		{
 			(*urls)[i] = g_strconcat ("file://", buffer, NULL);
 		}
