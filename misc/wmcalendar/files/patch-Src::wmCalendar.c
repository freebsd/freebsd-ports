--- Src/wmCalendar.c.orig	Thu Apr 24 16:23:05 2003
+++ Src/wmCalendar.c	Thu Apr 24 16:23:15 2003
@@ -55,6 +55,7 @@
  -----------------------------------------------------*/
 void initValues(){
     int i;
+    XpmColorSymbol colors[2] = { {"Back0", NULL, 0}, {"Back1", NULL, 0} };
     monthOffset = 0;
 
     /* Compute widths of months and digits */
@@ -72,7 +73,6 @@
     for (i = 0; i < 32; ++i) 
 	datetype[i][1] = 0;
 
-    XpmColorSymbol colors[2] = { {"Back0", NULL, 0}, {"Back1", NULL, 0} };
     dockapp_set_eventmask();
     dockapp_xpm2pixmap( wmCalendar_master2_xpm, &bg[1], &mask, colors, 0);
     dockapp_xpm2pixmap( wmCalendar_master_xpm, &bg[0], &mask, colors, 0);
