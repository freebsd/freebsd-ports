--- src/wmnd.c.orig	Sun Sep 22 09:23:35 2002
+++ src/wmnd.c	Sun Sep 22 09:23:55 2002
@@ -1204,10 +1204,7 @@
   }
 
   /* draw rx/tx rate */
-  /* TODO
-  p -= 4; sets p to his[58] or so
-  draw_rate(p[in], p[out]); */
-  p = ptr->avg;
+  p -= 4; // sets p to his[58] or so
   draw_rate(p[in], p[out]);
 
   if (bit_get(CFG_MAXSCREEN))
