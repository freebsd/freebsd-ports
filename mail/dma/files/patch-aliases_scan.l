--- ./aliases_scan.l.orig	2010-10-04 21:03:33.000000000 +0200
+++ ./aliases_scan.l	2010-10-18 13:25:47.330077534 +0200
@@ -3,8 +3,6 @@
 #include <string.h>
 #include "aliases_parse.h"
 
-#define YY_NO_INPUT
-
 int yylex(void);
 %}
 
