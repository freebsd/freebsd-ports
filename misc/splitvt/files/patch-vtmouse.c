--- vtmouse.c.orig	Sat Jun  3 14:05:57 2000
+++ vtmouse.c	Wed Jun 18 04:46:02 2003
@@ -8,6 +8,7 @@
 #define SPLITVT_SOURCE
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "vtmouse.h"
 
 extern FILE *safe_popen();		/* From misc.c */
