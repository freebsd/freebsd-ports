--- Config/exports.l.orig	2021-09-06 22:20:46 UTC
+++ Config/exports.l
@@ -14,7 +14,7 @@
 
 #define YY_NO_UNPUT
 
-YYSTYPE yylval;
+extern YYSTYPE yylval;
 extern int e_error;
 
 /*
@@ -67,4 +67,4 @@ OLDNET {IP}"/"{IP}
 
 .			{ return *yytext; }
 \n			{ return '\n'; }
-   
\ No newline at end of file
+   
