--- ./uget-gtk/UgApp-gtk-callback.c.orig	2014-07-12 12:08:24.000000000 +0000
+++ ./uget-gtk/UgApp-gtk-callback.c	2014-07-12 12:08:40.000000000 +0000
@@ -1334,10 +1334,12 @@
 	ug_launch_uri ("http://ugetdm.com/reportbug");
 }
 
+/*
 void    on_check_updates (GtkWidget* widget, UgAppGtk* app)
 {
 	ug_launch_uri ("http://ugetdm.com/versioncheck?v=" PACKAGE_VERSION);
 }
+*/
 
 void	on_about (GtkWidget* widget, UgAppGtk* app)
 {
@@ -2008,8 +2010,10 @@
 			G_CALLBACK (on_support_forum), app);
 	g_signal_connect (menubar->help.submit_feedback, "activate",
 			G_CALLBACK (on_submit_feedback), app);
+	/*
 	g_signal_connect (menubar->help.check_updates, "activate",
 			G_CALLBACK (on_check_updates), app);
+	*/
 	g_signal_connect (menubar->help.report_bug, "activate",
 			G_CALLBACK (on_report_bug), app);
 	g_signal_connect (menubar->help.about_uget, "activate",
