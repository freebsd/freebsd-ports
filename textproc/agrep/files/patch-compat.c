--- compat.c.orig	1992-01-21 14:36:26.000000000 +0100
+++ compat.c	2011-11-27 13:25:35.000000000 +0100
@@ -1,17 +1,18 @@
 /* test the conflicts between options */
 #include <stdio.h>
+#include <stdlib.h>
 
 extern int FILENAMEONLY, APPROX, PAT_FILE, COUNT, INVERSE, BESTMATCH;
-extern FILEOUT;
-extern REGEX;
-extern DELIMITER;
-extern WHOLELINE;
-extern LINENUM;
-extern I, S, DD;
-extern JUMP;
+extern int FILEOUT;
+extern int REGEX;
+extern int DELIMITER;
+extern int WHOLELINE;
+extern int LINENUM;
+extern int I, S, DD;
+extern int JUMP;
 extern char Progname[32];
 
-compat()
+void compat()
 {
 int i, j, k;
 	if(BESTMATCH)  if(COUNT || FILENAMEONLY || APPROX || PAT_FILE) {
