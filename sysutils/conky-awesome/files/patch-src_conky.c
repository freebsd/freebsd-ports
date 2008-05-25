--- src/conky.c.orig	2008-05-24 12:23:40.000000000 -0400
+++ src/conky.c	2008-05-24 12:24:07.000000000 -0400
@@ -5798,7 +5798,7 @@
 	int added;
 	width_of_s = get_string_width(s);
 	if (out_to_console) {
-		printf("%s\n", s);
+		printf("%s\n\n", s);
 		fflush(stdout);   /* output immediately, don't buffer */
 	}
 	memset(tmpstring1,0,TEXT_BUFFER_SIZE);
