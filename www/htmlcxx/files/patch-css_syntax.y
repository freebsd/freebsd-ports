--- css/css_syntax.y.orig	2011-02-13 22:24:53 UTC
+++ css/css_syntax.y
@@ -1,16 +1,17 @@
 %{
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "css_lex.h"
 #include "parser.h"
 
-#define YYPARSE_PARAM yyparam
 #define YYERROR_VERBOSE 1
 //#define YYDEBUG 1
 
 %}
 
 %pure_parser
+%parse-param { struct selector_list_t **yyparam }
 
 %union {
 	char *lexeme;
@@ -571,7 +572,7 @@ hexcolor
 
 %%
 
-int yyerror(char *s) {
+int yyerror(struct selector_list_t **yyparam, char *s) {
 #if YYDEBUG
 	fprintf(stderr, "Error: %s\n", s);
 #endif
