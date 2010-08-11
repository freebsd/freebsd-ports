--- ./aliases_scan.l.orig	2010-08-10 17:48:35.000000000 +0200
+++ ./aliases_scan.l	2010-08-11 19:54:44.877687647 +0200
@@ -3,8 +3,6 @@
 #include <string.h>
 #include "aliases_parse.h"
 
-#define YY_NO_INPUT
-
 int yylex(void);
 %}
 
