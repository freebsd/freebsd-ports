--- ifcico/flaglex.l.orig	1995-03-04 09:56:34 UTC
+++ ifcico/flaglex.l
@@ -1,3 +1,4 @@
+%option noyywrap
 %{
 #include <stdlib.h>
 #include <string.h>
@@ -8,10 +9,6 @@
 static char *yyPTR = NULL;
 static int yyBUFL;
 
-#ifndef yywrap
-#define yywrap() 1
-#endif
-
 #ifdef FLEX_SCANNER
 
 #undef YY_INPUT
