--- checkfile.c.orig	1992-01-17 19:14:42 UTC
+++ checkfile.c
@@ -65,6 +65,7 @@ int ftype;
         return ISSOCKET;
       }
 */
+      return 0;
     }
 }
 
