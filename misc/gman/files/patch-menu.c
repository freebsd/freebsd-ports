--- menu.c.orig	Fri Mar 30 09:36:30 2001
+++ menu.c	Fri Mar 30 09:36:47 2001
@@ -588,7 +588,7 @@
 	}
 }
 
-static status_bar_callback (GtkWidget *widget, gpointer   data)
+static int status_bar_callback (GtkWidget *widget, gpointer   data)
 {
 	int k,k2;
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
