--- generic/bltUtil.c.orig	2010-09-18 00:07:43.000000000 +0200
+++ generic/bltUtil.c	2013-11-19 09:26:20.000000000 +0100
@@ -345,7 +345,7 @@
 #if HAVE_UTF
 int
 Blt_DictionaryCompare(left, right)
-    char *left, *right;
+    CONST char *left, *right;
 {
     Tcl_UniChar uniLeft, uniRight, uniLeftLower, uniRightLower;
     int diff, zeros;
@@ -643,7 +643,7 @@
 #undef fopen
 FILE *
 Blt_OpenUtfFile(fileName, mode)
-    char *fileName, *mode;
+    CONST char *fileName, *mode;
 {
     Tcl_DString dString;
     FILE *f;
