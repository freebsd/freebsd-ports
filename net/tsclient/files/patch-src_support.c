--- src/support.c.orig	Thu Jul  3 16:20:04 2003
+++ src/support.c	Fri Jul  4 19:09:54 2003
@@ -566,7 +566,7 @@
 
   } else {
     // clean up and exit
-    g_free (cmd);
+    /*g_free (cmd);*/
     return 1;  
   }
   // clean up and exit
