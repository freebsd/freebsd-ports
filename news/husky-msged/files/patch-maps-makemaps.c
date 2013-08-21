--- maps/makemaps.c.orig	1999-10-15 05:24:42.000000000 +0800
+++ maps/makemaps.c	2013-08-21 18:13:36.000000000 +0800
@@ -13,6 +13,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 #include <ctype.h>
 #include <string.h>
 
@@ -527,19 +528,30 @@
 
 int save(void)
 {
-    FILE *fr = fopen("readmaps.dat","wb");
-    FILE *fw = fopen("writmaps.dat","wb");
+    char saveread[PATH_MAX], savewrit[PATH_MAX];
+    char *suffix;
+    FILE *fr, *fw;
     unsigned char header[12];
     int i;
 
+    suffix = getenv("MAKEMAPS_SAVEFILE_SUFFIX");
+    if (suffix == NULL)
+        suffix = ".dat";
+
+    snprintf(saveread, sizeof(saveread), "readmaps%s", suffix);
+    snprintf(savewrit, sizeof(savewrit), "writmaps%s", suffix);
+
+    fr = fopen(saveread, "wb");
+    fw = fopen(savewrit, "wb");
+
     if (fr == NULL)
     {
-        fprintf (stderr, "Cannot write readmaps.dat.\n");
+        fprintf (stderr, "Cannot write %s.\n", saveread);
         goto erro;
     }
     if (fw == NULL)
     {
-        fprintf (stderr, "Cannot write writmaps.dat.\n");
+        fprintf (stderr, "Cannot write %s.\n", savewrit);
         goto erro;
     }
 
@@ -595,8 +607,8 @@
             fclose(fr);
         }
     }
-    unlink("readmaps.dat");
-    unlink("writmaps.dat");
+    unlink(saveread);
+    unlink(savewrit);
     return 0;
 }
 
