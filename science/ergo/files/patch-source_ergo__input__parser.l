--- source/ergo_input_parser.l.orig	2020-05-14 00:05:15 UTC
+++ source/ergo_input_parser.l
@@ -32,7 +32,7 @@ static int yyget_debug(void);
 static void yyset_debug(int  bdebug);
 static int yylex_destroy(void);
 */
-extern int fileno(FILE *stream);
+//extern int fileno(FILE *stream);
 /* Following needed for flex-2.5.33-5 as in F7. */
 void yyset_lineno (int  line_number );
 int yyget_lineno  (void);
