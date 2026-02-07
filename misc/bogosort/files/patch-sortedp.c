--- sortedp.c.orig	Wed Aug 11 15:30:34 2004
+++ sortedp.c	Wed Aug 11 15:30:49 2004
@@ -38,6 +38,8 @@
 {
     int i;
 
+    if (lines[0] == NULL)
+	    return 1;
     for (i = 1; lines[i] != NULL; i++)
 	if (strcmp(lines[i - 1], lines[i]) > 0)
 	    return 0;
