--- compiler/scan.l.orig       Tue Nov 23 04:47:01 2004
+++ compiler/scan.l    Thu Apr 14 18:46:07 2005
@@ -24,7 +24,6 @@
 */
 
 %{
-#include "htcoblib.h"
 #include "htglobals.h"
 #include <ctype.h>
 
@@ -91,6 +90,7 @@
 
 #include "htcoboly.h"
 #include "htcobol.tab.h"    /* definitions from YACC */
+#include "htcoblib.h"
 #include "reswords.h"
 
 #define TOKTEXT_SIZE 1024
