--- Smooth/utils/draw_arrows.c.orig	Mon Nov  3 03:14:48 2003
+++ Smooth/utils/draw_arrows.c	Mon Nov  3 03:15:05 2003
@@ -381,10 +381,6 @@
           ah = 2*aw - 1;
         }  
 
-        if ((ah < 3) || (aw < 5)) {
-          ah = 3;
-          aw = 5;
-        }
 	aw += extra_tail;
       } else { 
         gfloat tmp=((aw+1)/2) - ((height%2)?1:0);
