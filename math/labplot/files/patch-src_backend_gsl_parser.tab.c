The function strtod_l is defined in xlocale.h .

--- src/backend/gsl/parser.tab.c.orig	2017-04-04 13:04:15 UTC
+++ src/backend/gsl/parser.tab.c
@@ -65,7 +65,7 @@
 /* Line 371 of yacc.c  */
 #line 3 "parser.y"
 
-#include <locale.h>
+#include <xlocale.h>
 #include "parser.h"
 
 /* Line 371 of yacc.c  */
