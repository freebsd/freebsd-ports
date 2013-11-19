--- generic/bltGrPen.c.orig	2013-11-18 17:53:49.000000000 +0100
+++ generic/bltGrPen.c	2013-11-18 17:54:24.000000000 +0100
@@ -475,13 +475,13 @@
     Tcl_Interp *interp;
     Graph *graphPtr;
     int argc;
-    char *argv[];
+    CONST char *argv[];
 {
     int flags;
     Pen *penPtr;
     int nNames, nOpts;
     int redraw;
-    char **options;
+    CONST char **options;
     register int i;
 
     /* Figure out where the option value pairs begin */
@@ -491,7 +491,7 @@
 	if (argv[i][0] == '-') {
 	    break;
 	}
-	if (NameToPen(graphPtr, argv[i]) == NULL) {
+	if (NameToPen(graphPtr, (char *)argv[i]) == NULL) {
 	    return TCL_ERROR;
 	}
     }
@@ -501,7 +501,7 @@
 
     redraw = 0;
     for (i = 0; i < nNames; i++) {
-	penPtr = NameToPen(graphPtr, argv[i]);
+	penPtr = NameToPen(graphPtr, (char *)argv[i]);
 	flags = TK_CONFIG_ARGV_ONLY | (penPtr->flags & (ACTIVE_PEN|NORMAL_PEN));
 	if (nOpts == 0) {
 	    return Tk_ConfigureInfo(interp, graphPtr->tkwin, 
