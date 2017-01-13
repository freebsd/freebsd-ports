--- src/ass.y.orig	2005-04-22 05:31:53 UTC
+++ src/ass.y
@@ -25,17 +25,17 @@
 #include "ass.h"
 #include "ass.tab.h"
 
-#define 		YYLEX_PARAM 	lexer_ctl
-#define 		YYPARSE_PARAM 	lexer_ctl
 #define 		line 			(((lexerctl_t*)lexer_ctl)->line)
 #define 		pos 			(((lexerctl_t*)lexer_ctl)->c)
 
-int yyerror( const char *s );
+int yyerror(void *lexer_ctl, const char *s);
 int yylex (YYSTYPE *lval, void* lexer_ctl);
 
 %}
 
-%pure_parser
+%define api.pure
+%lex-param {void *lexer_ctl}
+%parse-param {void *lexer_ctl}
 
 %union{
 	int 	letter;
@@ -258,7 +258,7 @@ var_t Op(var_t var1, var_t var2, int op_
 	return res;
 }
 
-int yyerror (const char *s) /* вызывается yyparse в случае ошибки */
+int yyerror (void *lexer_ctl, const char *s) /* вызывается yyparse в случае ошибки */
 {
 	printf ("\n(error in template)\n");
 	return 1;
