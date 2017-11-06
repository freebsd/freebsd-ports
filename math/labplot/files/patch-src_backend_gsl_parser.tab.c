The function strtod_l is defined in xlocale.h .

--- src/backend/gsl/parser.tab.c.orig	2017-04-23 19:52:39 UTC
+++ src/backend/gsl/parser.tab.c
@@ -67,7 +67,7 @@

 #include <string.h>
 #include <ctype.h>
-#include <locale.h>
+#include <xlocale.h>
 #include "parser.h"
 #include "constants.h"
 #include "functions.h"
