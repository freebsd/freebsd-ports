--- generic/bltTabset.c.orig	2013-11-19 09:28:40.000000000 +0100
+++ generic/bltTabset.c	2013-11-19 09:30:50.000000000 +0100
@@ -2093,7 +2093,7 @@
         return TCL_OK;
     }
     Tcl_ResetResult(setPtr->interp);
-    if (GetTabByIndex(setPtr, string, tabPtrPtr) != TCL_OK) {
+    if (GetTabByIndex(setPtr, string, tabPtrPtr, INVALID_OK) != TCL_OK) {
         return TCL_ERROR;	/* Can't find node. */
     }
     return TCL_OK;
@@ -2105,7 +2105,7 @@
     char *string,
     Tab **tabPtrPtr)
 {
-    if (GetTabByIndex(setPtr, string, tabPtrPtr) == TCL_OK) {
+    if (GetTabByIndex(setPtr, string, tabPtrPtr, INVALID_OK) == TCL_OK) {
         return TCL_OK;
     }
     Tcl_ResetResult(setPtr->interp);
@@ -3690,7 +3690,7 @@
 	    result = TCL_ERROR;
 	    goto finish;
 	}
-	tabPtr = CreateTab(setPtr, tName, &dStr);
+	tabPtr = CreateTab(setPtr, tName);
 	if (tabPtr == NULL) {
              result = TCL_ERROR;
              goto finish;
@@ -4049,7 +4049,7 @@
         return TCL_ERROR;
     }
     Tcl_DecrRefCount(objPtr);
-    if (argc>3 && GetTabByIndex(setPtr, argv[3], &tabPtr) != TCL_OK) {
+    if (argc>3 && GetTabByIndex(setPtr, argv[3], &tabPtr, INVALID_OK) != TCL_OK) {
         return TCL_ERROR;	/* Can't find node. */
     }
     if (tabPtr == NULL && optInd != OP_STARTIMAGE && optInd != OP_STARTIMAGE) {
