--- src/support.c.orig	Thu Jul  3 22:20:04 2003
+++ src/support.c	Fri Jul  4 21:04:57 2003
@@ -566,7 +566,7 @@
 
   } else {
     // clean up and exit
-    g_free (cmd);
+/*    g_free (cmd);*/
     return 1;  
   }
   // clean up and exit
