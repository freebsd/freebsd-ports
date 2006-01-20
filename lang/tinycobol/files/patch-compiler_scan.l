--- compiler/scan.l.orig	Thu Jul 21 14:57:46 2005
+++ compiler/scan.l	Thu Jan 19 21:08:45 2006
@@ -24,7 +24,6 @@
 */
 
 %{
-#include "htcoblib.h"
 #include "htglobals.h"
 #include <ctype.h>
 
@@ -93,6 +92,7 @@
 
 #include "htcoboly.h"
 #include "htcobol.tab.h"    /* definitions from YACC */
+#include "htcoblib.h"
 #include "reswords.h"
 
 #define TOKTEXT_SIZE 1024
