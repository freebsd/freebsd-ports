--- pan/base/text-massager.c.orig	Mon Jan 26 00:51:26 2004
+++ pan/base/text-massager.c	Mon Jan 26 00:55:48 2004
@@ -250,23 +250,29 @@
 	char * pch;
 	char * line_start;
 	char * end;
+	int    pos;
 
 	/* walk through the entire string */
 	linefeed_here = NULL;
-	for (line_start=pch=str->str, end=line_start+str->len; pch!=end; )
+	for (pos = 0, line_start=pch=str->str, end=line_start+str->len; pch<end; )
 	{
 		/* a linefeed could go here; remember this space */
-		if (isspace((guchar)*pch) || *pch=='\n')
+		if (g_unichar_isspace(g_utf8_get_char (pch)) || *pch=='\n')
 			linefeed_here = pch;
 
 		/* line's too long; add a linefeed if we can */
-		if (pch-line_start>=column && linefeed_here!=NULL)
+		if (pos>=column && linefeed_here!=NULL)
 		{
 			*linefeed_here = '\n';
 			pch = line_start = linefeed_here + 1;
 			linefeed_here = NULL;
+			pos = 0;
+		}
+		else 
+		{
+			pch = g_utf8_next_char (pch);
+			++ pos;
 		}
-		else ++pch;
 	}
 }
 
