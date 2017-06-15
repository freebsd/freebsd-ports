The function strtod_l is defined in xlocale.h .

--- src/backend/gsl/parser.y.orig	2017-03-29 08:51:19 UTC
+++ src/backend/gsl/parser.y
@@ -1,7 +1,7 @@
 /* LabPlot : parser.y	*/
 
 %{
-#include <locale.h>
+#include <xlocale.h>
 #include "parser.h"
 %}
 
