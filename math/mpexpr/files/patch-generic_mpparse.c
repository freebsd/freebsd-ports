--- generic/mpparse.c.orig	2013-11-06 15:29:52.000000000 +0100
+++ generic/mpparse.c	2013-11-06 15:36:11.000000000 +0100
@@ -283,7 +283,9 @@
 	    continue;
 	} else if (c == '\0') {
 	    Tcl_ResetResult(interp);
-	    sprintf(interp->result, "missing %c", termChar);
+            char buf[10];
+	    sprintf(buf, "missing %c", termChar);
+            Tcl_SetObjResult(interp, Tcl_NewStringObj(buf, -1));
 	    *termPtr = string-1;
 	    return TCL_ERROR;
 	} else {
@@ -349,12 +351,12 @@
         if (result != TCL_OK) {
 	    return result;
         }
-        length = strlen(interp->result);
+        length = strlen(Tcl_GetStringResult(interp));
         shortfall = length + 1 - (pvPtr->end - pvPtr->next);
         if (shortfall > 0) {
 	    (*pvPtr->expandProc)(pvPtr, shortfall);
         }
-        strcpy(pvPtr->next, interp->result);
+        strcpy(pvPtr->next, Tcl_GetStringResult(interp));
         pvPtr->next += length;
         Tcl_ResetResult(interp);
     } else {
