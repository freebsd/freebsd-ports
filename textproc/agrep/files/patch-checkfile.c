--- checkfile.c.orig	1992-01-17 20:14:42.000000000 +0100
+++ checkfile.c	2011-11-27 13:19:28.000000000 +0100
@@ -65,6 +65,7 @@
         return ISSOCKET;
       }
 */
+      return 0;
     }
 }
 
