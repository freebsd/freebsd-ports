The function strtod_l is defined in xlocale.h .

--- src/backend/gsl/parser.y.orig	2017-04-02 07:47:32 UTC
+++ src/backend/gsl/parser.y
@@ -30,7 +30,7 @@
 %{
 #include <string.h>
 #include <ctype.h>
-#include <locale.h>
+#include <xlocale.h>
 #include "parser.h"
 #include "constants.h"
 #include "functions.h"
