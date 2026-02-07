--- generic/bltInit.c.orig	2013-11-19 09:31:51.000000000 +0100
+++ generic/bltInit.c	2013-11-19 09:31:51.000000000 +0100
@@ -510,7 +510,6 @@
     Tcl_Interp *interp;		/* Interpreter to add extra commands */
 {
     int flags;
-    int dostub = 0;
 
     flags = (int)Tcl_GetAssocData(interp, BLT_THREAD_KEY, NULL);
     if ((flags & BLT_TCL_CMDS) == 0) {
@@ -562,11 +561,11 @@
 	Blt_RegisterArrayObj(interp);
 	bltNaN = MakeNaN();
 #ifdef USE_BLT_STUBS
-	if (Tcl_PkgProvideEx(interp, "BLT", BLT_PATCH_LEVEL, &bltStubs) != TCL_OK) {
+	if (Tcl_PkgProvideEx(interp, "BLT", BLT_VERSION, &bltStubs) != TCL_OK) {
 	    return TCL_ERROR;
 	}
 #else
-	if (Tcl_PkgProvideEx(interp, "BLT", BLT_PATCH_LEVEL, NULL) != TCL_OK) {
+	if (Tcl_PkgProvideEx(interp, "BLT", BLT_VERSION, NULL) != TCL_OK) {
 	    return TCL_ERROR;
 	}
 #endif
