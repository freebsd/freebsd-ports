--- grammar/lexer.l.orig	2014-10-02 17:44:03.599344945 -0500
+++ grammar/lexer.l	2014-10-02 17:44:08.808344494 -0500
@@ -31,7 +31,7 @@
 %{
 #include "config.h"
 #include "parserif.h"
-extern char *strdup(__const char*); /* somehow we may not get this from string.h... */
+//extern char *strdup(__const char*); /* somehow we may not get this from string.h... */
 %}
 
 %option noyywrap nodefault case-insensitive yylineno
