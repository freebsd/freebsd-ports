--- generic/bltGrElem.c.orig	2013-11-18 17:47:27.000000000 +0100
+++ generic/bltGrElem.c	2013-11-18 17:48:30.000000000 +0100
@@ -1658,7 +1658,7 @@
     Graph *graphPtr;		/* Graph widget */
     Tcl_Interp *interp;		/* Interpreter to report results to */
     int argc;			/* Number of element names */
-    char **argv;		/* List of element names */
+    CONST char **argv;		/* List of element names */
 {
     Element *elemPtr;
     ClosestSearch search;
@@ -1710,7 +1710,7 @@
     if (i < argc) {
 
 	for ( /* empty */ ; i < argc; i++) {
-	    if (NameToElement(graphPtr, argv[i], &elemPtr) != TCL_OK) {
+	    if (NameToElement(graphPtr, (char *)argv[i], &elemPtr) != TCL_OK) {
 		return TCL_ERROR;	/* Can't find named element */
 	    }
  	    if (elemPtr->hidden) {
@@ -1811,12 +1811,12 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char *argv[];
+    CONST char *argv[];
 {
     Element *elemPtr;
     int flags;
     int numNames, numOpts;
-    char **options;
+    CONST char **options;
     register int i;
 
     /* Figure out where the option value pairs begin */
@@ -1826,7 +1826,7 @@
 	if (argv[i][0] == '-') {
 	    break;
 	}
-	if (NameToElement(graphPtr, argv[i], &elemPtr) != TCL_OK) {
+	if (NameToElement(graphPtr, (char *)argv[i], &elemPtr) != TCL_OK) {
 	    return TCL_ERROR;	/* Can't find named element */
 	}
     }
@@ -1835,7 +1835,7 @@
     options = argv + numNames;	/* Start of options in argv  */
 
     for (i = 0; i < numNames; i++) {
-	NameToElement(graphPtr, argv[i], &elemPtr);
+	NameToElement(graphPtr, (char *)argv[i], &elemPtr);
 	flags = TK_CONFIG_ARGV_ONLY;
 	if (numOpts == 0) {
 	    return Tk_ConfigureInfo(interp, graphPtr->tkwin, 
