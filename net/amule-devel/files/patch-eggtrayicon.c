--- src/eggtrayicon.c.orig	Sat Oct 23 05:41:59 2004
+++ src/eggtrayicon.c	Sat Oct 23 05:50:38 2004
@@ -75,7 +75,7 @@
 
 static GdkFilterReturn
 egg_tray_icon_manager_filter (GdkXEvent *xevent, GdkEvent *event, gpointer user_data)
-{ (void)event;
+{
   EggTrayIcon *icon = user_data;
   XEvent *xev = (XEvent *)xevent;
 
