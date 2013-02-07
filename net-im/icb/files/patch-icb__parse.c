--- icb/parse.c.orig	2000-12-15 13:29:18.000000000 +0900
+++ icb/parse.c	2012-10-25 18:30:39.000000000 +0900
@@ -6,6 +6,10 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 extern Tcl_Interp *interp;
 char *nextword();
 
