$FreeBSD$

--- src/parse.lex.orig	Mon Mar 29 21:57:12 2004
+++ src/parse.lex	Mon Mar 29 21:57:46 2004
@@ -41,6 +41,7 @@
 #include "error.h"
 #include "parse_util.h"
 extern void yyerror();
+extern YYSTYPE yylval;
 
 #define MAX_INCLUDE_DEPTH 10
 static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
