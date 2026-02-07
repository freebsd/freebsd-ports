--- generic/bltGrAxis.c.orig	2013-11-18 17:44:53.000000000 +0100
+++ generic/bltGrAxis.c	2013-11-18 17:46:54.000000000 +0100
@@ -3436,7 +3436,7 @@
     Graph *graphPtr;
     Axis *axisPtr;
     int argc;
-    char *argv[];
+    CONST char *argv[];
 {
     int flags;
 
@@ -3858,11 +3858,11 @@
 ConfigureVirtualOp(graphPtr, argc, argv)
     Graph *graphPtr;
     int argc;
-    char *argv[];
+    CONST char *argv[];
 {
     Axis *axisPtr;
     int nNames, nOpts;
-    char **options;
+    CONST char **options;
     register int i;
 
     /* Figure out where the option value pairs begin */
@@ -3872,7 +3872,7 @@
 	if (argv[i][0] == '-') {
 	    break;
 	}
-	if (NameToAxis(graphPtr, argv[i], &axisPtr) != TCL_OK) {
+	if (NameToAxis(graphPtr, (char *)argv[i], &axisPtr) != TCL_OK) {
 	    return TCL_ERROR;
 	}
     }
@@ -3881,10 +3881,10 @@
     options = argv + i;		/* Start of options in argv  */
 
     for (i = 0; i < nNames; i++) {
-	if (NameToAxis(graphPtr, argv[i], &axisPtr) != TCL_OK) {
-	    return TCL_ERROR;
-	}
-	if (ConfigureOp(graphPtr, axisPtr, nOpts, options) != TCL_OK) {
+        if (NameToAxis(graphPtr, (char *)argv[i], &axisPtr) != TCL_OK) {
+            return TCL_ERROR;
+        }
+        if (ConfigureOp(graphPtr, axisPtr, nOpts, options) != TCL_OK) {
 	    break;
 	}
     }
