--- sendd/params_gram.y.orig	2023-04-11 00:49:19 UTC
+++ sendd/params_gram.y
@@ -77,7 +77,7 @@ static void yyerror(char *);
 extern char *params_text;
 extern int params_lex(void);
 
-int params_linecnt;
+extern int params_linecnt;
 
 static const char *derfile;
 static const char *keyfile;
