--- src/conky.c.orig	2008-05-27 00:43:05.000000000 -0400
+++ src/conky.c	2008-05-27 00:43:36.000000000 -0400
@@ -6513,7 +6513,7 @@ static void draw_string(const char *s)
 
 	width_of_s = get_string_width(s);
 	if (out_to_console) {
-		printf("%s\n", s);
+		printf("%s\n\n", s);
 		fflush(stdout);	/* output immediately, don't buffer */
 	}
 	memset(tmpstring1, 0, text_buffer_size);
