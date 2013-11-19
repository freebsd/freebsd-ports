--- generic/bltGrMarker.c.orig	2013-11-18 17:52:05.000000000 +0100
+++ generic/bltGrMarker.c	2013-11-18 17:53:22.000000000 +0100
@@ -4274,13 +4274,13 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
 {
     Marker *markerPtr;
     int flags = TK_CONFIG_ARGV_ONLY;
     char *oldName;
     int nNames, nOpts;
-    char **options;
+    CONST char **options;
     register int i;
     int under;
 
@@ -4291,7 +4291,7 @@
 	if (argv[i][0] == '-') {
 	    break;
 	}
-	if (NameToMarker(graphPtr, argv[i], &markerPtr) != TCL_OK) {
+	if (NameToMarker(graphPtr, (char *)argv[i], &markerPtr) != TCL_OK) {
 	    return TCL_ERROR;
 	}
     }
@@ -4300,7 +4300,7 @@
     options = argv + nNames;	/* Start of options in argv  */
 
     for (i = 0; i < nNames; i++) {
-	NameToMarker(graphPtr, argv[i], &markerPtr);
+	NameToMarker(graphPtr, (char *)argv[i], &markerPtr);
 	if (nOpts == 0) {
 	    return Tk_ConfigureInfo(interp, graphPtr->tkwin, 
 		markerPtr->classPtr->configSpecs, (char *)markerPtr, 
