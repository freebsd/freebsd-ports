--- lib/subtitle/subread.c.orig	Tue Oct  5 15:47:53 2004
+++ lib/subtitle/subread.c	Tue Oct  5 15:49:02 2004
@@ -100,12 +100,14 @@
     if (sl->lines < SUBTITLE_MAX_LINES && txt)
     {
 	int n = 0;
-	char* b = trim_spaces(txt);
+	char* b;
+        char* t;
+        b = trim_spaces(txt);
         trim_http(b);
 
 	// skip color and font-style change - not supported right now
 	// {c:$00ffff} {y:i}
-	char* t = strchr(b, '{');
+	t = strchr(b, '{');
 	if (t)
 	{
 	    char u = toupper(t[1]);
