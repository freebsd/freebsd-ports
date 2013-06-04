--- icb/tcl.c.orig	2000-10-02 20:25:55.000000000 +0900
+++ icb/tcl.c	2012-10-25 18:22:17.000000000 +0900
@@ -3,6 +3,9 @@
 /* TCL interface */
 #include "config.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -70,8 +73,8 @@
 	for (x = 0; defprocs[x] != 0; x++)
 		if (Tcl_Eval(interp, defprocs[x]) != TCL_OK) {
 			printf("Default binding failed: %s\r\n", defprocs[x]);
-			if (*interp->result != 0)
-				puts(interp->result);
+			if (Tcl_GetStringResult(interp) != 0)
+				puts(Tcl_GetStringResult(interp));
 		}
 
 }
