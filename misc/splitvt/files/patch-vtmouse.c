--- vtmouse.c.orig	Sat Jun  3 23:05:57 2000
+++ vtmouse.c	Sat Oct  7 14:37:42 2006
@@ -8,6 +8,8 @@
 #define SPLITVT_SOURCE
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "vtmouse.h"
 
 extern FILE *safe_popen();		/* From misc.c */
