--- src/main.c.orig	Fri Apr 26 14:29:08 2002
+++ src/main.c	Fri Apr 26 14:52:43 2002
@@ -394,7 +394,12 @@
 	for (i = 0; i < n; i++)
 	{
 		/* try to expand as files */
-		if (realpath (args[i], buffer) != NULL)
+		if (!strnstr(args[i], "ghelp:", strlen("ghelp:")) &&
+		    !strnstr(args[i], "toc:", strlen("toc:")) &&
+		    !strnstr(args[i], "info:", strlen("info:")) &&
+		    !strnstr(args[i], "main:", strlen("man:")) &&
+		    !strnstr(args[i], "gnome-help:", strlen("gnome-help")) &&
+		    realpath (args[i], buffer) != NULL)
 		{
 			(*urls)[i] = g_strconcat ("file://", buffer, NULL);
 		}
