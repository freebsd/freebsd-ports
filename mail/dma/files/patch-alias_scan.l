!
! Work around bug in FreeBSD 8.1 due to missing fix for:
! bin/139319: [patch] flex(1): fix prototypes, esp. when YY_NO_INPUT is defined
!
--- aliases_scan.l.orig	2012-01-03 13:54:05.000000000 +0000
+++ aliases_scan.l	2012-04-13 18:23:41.000000000 +0000
@@ -3,8 +3,6 @@
 #include <string.h>
 #include "aliases_parse.h"
 
-#define YY_NO_INPUT
-
 int yylex(void);
 %}
 
