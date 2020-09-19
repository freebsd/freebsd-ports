--- lex.yy.c.orig	2006-11-22 05:58:36 UTC
+++ lex.yy.c
@@ -276,7 +276,7 @@ static void yy_flex_free YY_PROTO(( void * ));
 #define yywrap() 1
 #define YY_SKIP_YYWRAP
 typedef unsigned char YY_CHAR;
-FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
+FILE *yyout = (FILE *) 0;
 typedef int yy_state_type;
 extern char *yytext;
 #define yytext_ptr yytext
