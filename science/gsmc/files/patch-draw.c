--- draw.c.orig	Sat Feb 11 12:42:26 2006
+++ draw.c	Sat Feb 11 12:42:59 2006
@@ -576,6 +576,7 @@
       break;
 
     default:
+      break;
     }
 
   }
@@ -591,6 +592,7 @@
   case 'o': strcpy(rv, "op"); break;
   case 'c': strcpy(rv, "sp"); break;
   default: 
+    break;
   }
 
 }
