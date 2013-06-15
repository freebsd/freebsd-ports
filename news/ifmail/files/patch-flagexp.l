--- ifcico/flaglex.l.orig	1995-03-04 10:56:34.000000000 +0100
+++ ifcico/flaglex.l	2013-05-27 15:29:03.783061252 +0200
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
