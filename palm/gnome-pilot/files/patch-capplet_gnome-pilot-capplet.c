--- capplet/gnome-pilot-capplet.c.orig	Mon Aug  2 20:10:43 2004
+++ capplet/gnome-pilot-capplet.c	Mon Aug  2 20:11:25 2004
@@ -183,6 +183,7 @@
 	init_widgets (gpcap);
 
  error:
+	return;
 }
 
 GnomePilotCapplet *
