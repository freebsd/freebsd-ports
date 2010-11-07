--- ./panel-plugin/cmdspawn.c.orig	2007-11-23 16:32:40.000000000 +0100
+++ ./panel-plugin/cmdspawn.c	2010-11-07 11:29:03.000000000 +0100
@@ -184,6 +184,7 @@
             return (-1);
         case 0:
             /* Redirect stdout/stderr to associated pipe's write-ends */
+            close(0); /* stdin is not used in child */
             for (i = 0; i < OUT_ERR; i++) {
                 j = i + 1; // stdout/stderr file descriptor
                 close (j);
@@ -199,6 +200,9 @@
         exit (-1);
     }
 
+    for (i = 0; i < OUT_ERR; i++)
+        close (aaiPipe[i][WR]); /* close write end of pipes in parent */
+
     /* Wait for child completion */
     if (wait == 1)
     {
@@ -231,10 +235,9 @@
     }
 
     End:
-    /* Close created pipes */
+    /* Close read end of pipes */
     for (i = 0; i < OUT_ERR; i++)
-        for (j = 0; j < RD_WR; j++)
-            close (aaiPipe[i][j]);
+        close (aaiPipe[i][RD]);
 
     return (-fError);
 }// Spawn()
