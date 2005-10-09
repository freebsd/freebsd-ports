--- src/input/input_cdda.c.orig	Mon Oct 10 00:51:19 2005
+++ src/input/input_cdda.c	Mon Oct 10 00:52:58 2005
@@ -1473,7 +1473,7 @@
     return;
   }
   else {
-    fprintf(fd, filecontent);
+    fprintf(fd, "%s", filecontent);
     fclose(fd);
   }
   
