--- capplet/gnome-pilot-druid.c.orig	Mon Aug  2 20:12:33 2004
+++ capplet/gnome-pilot-druid.c	Mon Aug  2 20:12:44 2004
@@ -181,6 +181,7 @@
 	init_widgets (gpd);
 
  error:
+	return;
 }
 
 
