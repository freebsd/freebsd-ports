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
 
@@ -78,14 +82,14 @@
 
 	/* Print the tcl result. */
 	if (result == TCL_OK) {
-		if (*interp->result != 0)
-			putl(interp->result, PL_SL);
+		if (Tcl_GetStringResult(interp) != 0)
+			putl(Tcl_GetStringResult(interp), PL_SL);
 	} else {
-		if (interp->result) {
+		if (Tcl_GetStringResult(interp)) {
 			sprintf(mbuf, 
 				"%s[=Error=] %s%s",
 				printcolor(ColERROR, ColSANE),
-				interp->result,
+				Tcl_GetStringResult(interp),
 				printcolor(ColSANE, ColSANE));
 			putl(mbuf, PL_SL);
 		} else {
