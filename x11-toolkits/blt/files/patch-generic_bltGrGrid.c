--- generic/bltGrGrid.c.orig	2013-11-18 17:49:30.000000000 +0100
+++ generic/bltGrGrid.c	2013-11-18 17:49:49.000000000 +0100
@@ -355,7 +355,7 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
 {
     Grid *gridPtr = (Grid *)graphPtr->gridPtr;
     int flags;
