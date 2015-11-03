--- src/html.c.orig	2015-08-19 11:12:02 UTC
+++ src/html.c
@@ -866,9 +866,6 @@ int yy_flex_debug = 0;
 char *yytext;
 #line 1 "html.l"
 #line 4 "html.l"
-#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
-extern int fileno(FILE *file);
-#endif
 
 #include <stdio.h>
 #include <string.h>
