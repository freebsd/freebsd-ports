--- generic/bltGrPs.c.orig	2013-11-19 09:13:57.000000000 +0100
+++ generic/bltGrPs.c	2013-11-19 09:16:50.000000000 +0100
@@ -406,7 +406,7 @@
     Graph *graphPtr;
     Tcl_Interp *interp;
     int argc;			/* Number of options in argv vector */
-    char **argv;		/* Option vector */
+    CONST char **argv;		/* Option vector */
 {
     int flags = TK_CONFIG_ARGV_ONLY;
     PostScript *psPtr = (PostScript *)graphPtr->postscript;
@@ -634,7 +634,7 @@
 static int
 PostScriptPreamble(graphPtr, fileName, psToken)
     Graph *graphPtr;
-    char *fileName;
+    CONST char *fileName;
     PsToken psToken;
 {
     PostScript *psPtr = (PostScript *)graphPtr->postscript;
@@ -829,7 +829,7 @@
 static int
 GraphToPostScript(graphPtr, ident, psToken)
     Graph *graphPtr;
-    char *ident;		/* Identifier string (usually the filename) */
+    CONST char *ident;		/* Identifier string (usually the filename) */
     PsToken psToken;
 {
     int x, y, width, height;
@@ -1110,12 +1110,12 @@
     Graph *graphPtr;		/* Graph widget record */
     Tcl_Interp *interp;
     int argc;			/* Number of options in argv vector */
-    char **argv;		/* Option vector */
+    CONST char **argv;		/* Option vector */
 {
     PostScript *psPtr = (PostScript *)graphPtr->postscript;
     FILE *f = NULL;
     PsToken psToken;
-    char *fileName;		/* Name of file to write PostScript output
+    CONST char *fileName;		/* Name of file to write PostScript output
                                  * If NULL, output is returned via
                                  * interp->result. */
     fileName = NULL;
