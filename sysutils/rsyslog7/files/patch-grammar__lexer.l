--- grammar/lexer.l.orig	2014-09-30 16:44:49 UTC
+++ grammar/lexer.l
@@ -31,7 +31,7 @@
 %{
 #include "config.h"
 #include "parserif.h"
-extern char *strdup(char*); /* somehow we do not get this from string.h... */
+//extern char *strdup(char*); /* somehow we do not get this from string.h... */
 %}
 
 %option noyywrap nodefault case-insensitive yylineno
