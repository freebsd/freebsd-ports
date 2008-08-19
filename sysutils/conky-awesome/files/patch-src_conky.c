--- src/conky.c.orig	2008-08-19 16:02:53.000000000 -0700
+++ src/conky.c	2008-08-19 16:03:36.000000000 -0700
@@ -6672,7 +6672,7 @@ static void draw_string(const char *s)
 
 	width_of_s = get_string_width(s);
 	if ((output_methods & TO_STDOUT) && draw_mode == FG) {
-		printf("%s\n", s);
+		printf("%s\n\n", s);
 		fflush(stdout);	/* output immediately, don't buffer */
 	}
 	memset(tmpstring1, 0, text_buffer_size);
