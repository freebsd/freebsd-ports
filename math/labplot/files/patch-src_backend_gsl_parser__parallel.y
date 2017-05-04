The function strtod_l is defined in xlocale.h .

--- src/backend/gsl/parser_parallel.y.orig	2017-04-23 19:52:52 UTC
+++ src/backend/gsl/parser_parallel.y
@@ -34,7 +34,7 @@
 #include <string.h>
 #include <strings.h>	/* bzero */
 #include <ctype.h>
-#include <locale.h>
+#include <xlocale.h>
 #include "constants.h"
 #include "functions.h"
 #include "parser.h"
