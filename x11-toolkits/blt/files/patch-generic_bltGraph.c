--- generic/bltGraph.c.orig	2013-11-19 09:17:39.000000000 +0100
+++ generic/bltGraph.c	2013-11-19 09:20:27.000000000 +0100
@@ -887,7 +887,7 @@
 CreateGraph(interp, argc, argv, classUid)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
     Blt_Uid classUid;
 {
     Graph *graphPtr;
@@ -1082,7 +1082,7 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
 {
     int flags;
 
@@ -1926,7 +1926,7 @@
 NewGraph(interp, argc, argv, classUid)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
     Blt_Uid classUid;
 {
     Graph *graphPtr;
@@ -1968,7 +1968,7 @@
     int argc;
     char **argv;
 {
-    return NewGraph(interp, argc, argv, bltLineElementUid);
+    return NewGraph(interp, argc, (const char **)argv, bltLineElementUid);
 }
 
 /*
@@ -1995,7 +1995,7 @@
     int argc;
     char **argv;
 {
-    return NewGraph(interp, argc, argv, bltBarElementUid);
+    return NewGraph(interp, argc, (const char **)argv, bltBarElementUid);
 }
 
 /*
@@ -2022,7 +2022,7 @@
     int argc;
     char **argv;
 {
-    return NewGraph(interp, argc, argv, bltStripElementUid);
+    return NewGraph(interp, argc, (const char **)argv, bltStripElementUid);
 }
 
 /*
