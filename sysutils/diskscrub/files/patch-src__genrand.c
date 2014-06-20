--- ./src/genrand.c.orig	2014-06-19 20:53:05.000000000 -0300
+++ ./src/genrand.c	2014-06-19 20:53:18.000000000 -0300
@@ -106,7 +106,7 @@
                 buf[n] = result;
             }
 #endif
-            return;
+            return 0;
         }
     }
 
