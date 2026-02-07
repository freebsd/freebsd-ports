--- calendar.c.orig	2007-01-15 01:14:32.000000000 +0100
+++ calendar.c	2009-01-26 19:11:27.000000000 +0100
@@ -48,7 +48,7 @@
 
 
 
-void kill (GtkWidget * widget)
+void wmkill (GtkWidget * widget)
 {
     gtk_widget_destroy ((GtkWidget*)gtk_widget_get_toplevel(widget));
     gtk_main_quit ();
@@ -193,7 +193,7 @@
 	gtk_signal_connect(GTK_OBJECT (event_box), "button_press_event",
 			   GTK_SIGNAL_FUNC (move), NULL);
 	gtk_signal_connect(GTK_OBJECT (event_box2), "button_press_event",
-			   (GtkSignalFunc) kill, GTK_OBJECT(dayView));
+			   (GtkSignalFunc) wmkill, GTK_OBJECT(dayView));
 
 	gtk_widget_realize(dayView);
 	//	gtk_window_set_position(GTK_WINDOW (dayView),GTK_WIN_POS_CENTER_ON_PARENT);
