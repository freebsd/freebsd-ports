--- ftype.c.orig	Thu Sep  2 23:14:04 2004
+++ ftype.c	Thu Sep  2 23:14:25 2004
@@ -300,6 +300,7 @@
 	  goto err;
       return i;
     err:
+      break;
     }
   }
   return NONE;
