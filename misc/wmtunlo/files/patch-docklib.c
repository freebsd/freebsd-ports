--- docklib.c.orig	2020-09-17 11:16:57 UTC
+++ docklib.c
@@ -300,6 +300,7 @@ execCommand(char *command)
 /*****************/
 
 Window		Root;
+Display		*display;
 int			screen;
 int			x_fd;
 int			d_depth;
@@ -713,7 +714,7 @@ char text[MAX_LINE_LEN];
 
 		p_strcpy (text, "# ", MAX_LINE_LEN);
 		p_strcat (text, comment, MAX_LINE_LEN);
-		fprintf (prefs_filehandle, text);
+		fprintf (prefs_filehandle, "%s", text);
 }
 
 /*---------------------------------------------------------------------------*/
