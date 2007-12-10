--- folder.c.orig	2007-12-07 00:06:06.000000000 +0100
+++ folder.c	2007-12-07 00:06:26.000000000 +0100
@@ -2118,7 +2118,7 @@
           else
             {
               char *err = (errno >= 0 && errno <sys_nerr)? 
-                sys_errlist[errno] : "Unknown error";
+                (char *)sys_errlist[errno] : "Unknown error";
               ezfmWarning("Rename File Failed", err);                
             }
         }
