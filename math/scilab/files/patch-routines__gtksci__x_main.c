--- ./routines/gtksci/x_main.c.orig	Tue Mar 21 19:50:48 2006
+++ ./routines/gtksci/x_main.c	Tue Mar 21 19:51:50 2006
@@ -655,8 +655,8 @@
   /* sciprint("GetScreenProperty not implemented in gtk 1\r\n"); */
   return -1;
 #else 
-  start_sci_gtk();
   GdkScreen *screen =  gdk_screen_get_default();
+  start_sci_gtk();
   
   if(!strcmp(prop,"screensize_px"))
     {
@@ -714,9 +714,9 @@
   *iyres = 96;
   return 0;
 #else 
-  start_sci_gtk();
   GdkScreen *screen =  gdk_screen_get_default();
   double xres, yres;
+  start_sci_gtk();
   
   /*
    * there are 2.54 centimeters to an inch; so there are 25.4 millimeters.
