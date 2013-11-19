--- generic/bltGrHairs.c.orig	2013-11-18 17:50:12.000000000 +0100
+++ generic/bltGrHairs.c	2013-11-18 17:50:29.000000000 +0100
@@ -379,7 +379,7 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
 {
     Crosshairs *chPtr = graphPtr->crosshairs;
 
