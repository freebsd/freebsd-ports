--- tcl2c.c.orig	Sun Nov  3 04:15:11 2002
+++ tcl2c.c	Sun Oct  5 18:45:58 2003
@@ -43,6 +43,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <time.h>
 #include <errno.h>
 
 #define FALSE 0
@@ -123,6 +124,8 @@
     scriptName = malloc(fileNameLen + 1);
     strncpy(outNameC, argv[1], fileNameLen - 4);
     strncpy(outNameH, argv[1], fileNameLen - 4);
+    outNameC[fileNameLen-4]=0;
+    outNameH[fileNameLen-4]=0;
     baseName = (char *)strrchr(argv[1], '/');
     if (baseName != NULL)
     {
