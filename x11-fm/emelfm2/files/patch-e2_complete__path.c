--- src/command/complete/e2_complete__path.c	2008-03-22 03:58:43.000000000 +0100
+++ src/command/complete/e2_complete__path.c	2008-04-03 15:15:09.000000000 +0200
@@ -147,7 +147,7 @@
 	{
 		gchar *p1, *p2, *localpath;
 		p1 = g_utf8_next_char (strrchr (word, G_DIR_SEPARATOR));	//the 'real' word to complete
-		p2 = strndup (word, p1 - word);	//prefix for matches
+		p2 = g_strndup (word, p1 - word);	//prefix for matches
 		if (word[0] == G_DIR_SEPARATOR)
 		{	//word is an absolute path string
 			localpath = F_FILENAME_TO_LOCALE (p2);
