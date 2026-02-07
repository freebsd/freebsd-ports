--- generic/bltGrLegd.c.orig	2013-11-18 17:50:55.000000000 +0100
+++ generic/bltGrLegd.c	2013-11-18 17:51:07.000000000 +0100
@@ -1393,7 +1393,7 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    CONST char **argv;
 {
     int flags = TK_CONFIG_ARGV_ONLY;
     Legend *legendPtr;
