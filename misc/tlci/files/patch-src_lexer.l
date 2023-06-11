--- src/lexer.l.orig	2023-06-11 19:08:30 UTC
+++ src/lexer.l
@@ -49,7 +49,7 @@ void reset_lexer(void)
     YY_FLUSH_BUFFER;
 }
 /*********************************************************************************/
-heap_cell_t* get_token_pos()
+heap_cell_t* get_token_pos(void)
 {
     return heap_alloc_token_pos(tlci_heap,
         from_cstring(string_dup(filename)),
@@ -61,7 +61,7 @@ void yyerror(char *s)
     printf("%s:%d:%d: \033[31m%s:\033[0m Unexpected '%s'\n", filename, yylineno, tokenpos, s, yytext);
 }
 /*********************************************************************************/
-void switch_to_stdin()
+void switch_to_stdin(void)
 {
     filename = "<interactive>";
     yyin = stdin;
