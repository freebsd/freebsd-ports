--- generic/bltTed.c.orig	2013-10-30 11:55:26.000000000 +0100
+++ generic/bltTed.c	2013-10-30 11:57:39.000000000 +0100
@@ -1504,7 +1504,7 @@
 	tablePtr->flags |= ARRANGE_PENDING;
 	Tcl_DoWhenIdle(tablePtr->arrangeProc, tablePtr);
     }
-    interp->result = Tk_PathName(tedPtr->tkwin);
+    Tcl_SetObjResult(interp, Tcl_NewStringObj(Tk_PathName(tedPtr->tkwin), -1));
     tedPtr->flags |= LAYOUT_PENDING;
     EventuallyRedraw(tedPtr);
     return TCL_OK;
@@ -1678,7 +1678,7 @@
 	    tedPtr->activeRectArr[4].width = grip - 1;
 	    tedPtr->activeRectArr[4].height = grip - 1;
 
-	    interp->result = Tk_PathName(entryPtr->tkwin);
+        Tcl_SetObjResult(interp, Tcl_NewStringObj(Tk_PathName(entryPtr->tkwin), -1));
 	    active = 1;
 	    break;
 	}
@@ -1751,7 +1751,7 @@
 	tablePtr->flags |= ARRANGE_PENDING;
 	Tcl_DoWhenIdle(tablePtr->arrangeProc, tablePtr);
     }
-    interp->result = Tk_PathName(tedPtr->tkwin);
+    Tcl_SetObjResult(interp, Tcl_NewStringObj(Tk_PathName(tedPtr->tkwin), -1));
     tedPtr->flags |= LAYOUT_PENDING;
     EventuallyRedraw(tedPtr);
     return TCL_OK;
