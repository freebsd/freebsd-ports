--- tcl2c.c.orig	Tue Sep 23 21:49:35 2003
+++ tcl2c.c	Tue Oct 21 13:14:35 2003
@@ -50,6 +50,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#include <time.h>
 #include <errno.h>
 #include <time.h>
 #include <ctype.h>
@@ -429,6 +430,8 @@
     scriptName = malloc(fileNameLen + 1);
     strncpy(outNameC, inFileName, fileNameLen - 4);
     strncpy(outNameH, inFileName, fileNameLen - 4);
+    outNameC[fileNameLen-4]=0;
+    outNameH[fileNameLen-4]=0;
     baseName = (char *)strrchr(inFileName, '/');
     if (baseName != NULL)
     {
