--- bin/parser.c.orig	Tue Aug 10 14:33:43 2004
+++ bin/parser.c	Tue Aug 10 14:34:32 2004
@@ -460,7 +460,7 @@
 int 
 parser_get_next_line(struct parser_state * pstate)
 {
-	int len;
+	size_t len;
 	char *new_line;
 	char *next_stream_line;
 
