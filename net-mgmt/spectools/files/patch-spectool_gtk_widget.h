--- spectool_gtk_widget.h.orig	2014-06-10 21:28:10.000000000 +0200
+++ spectool_gtk_widget.h	2014-06-10 21:27:46.000000000 +0200
@@ -196,16 +196,16 @@ void spectool_widget_link_channel(GtkWid
 gint spectool_widget_timeout(gpointer *data);
 
 /* Calculate the channel clicked in */
-inline int spectool_widget_find_chan_pt(SpectoolWidget *wwidget, int x, int y);
+int spectool_widget_find_chan_pt(SpectoolWidget *wwidget, int x, int y);
 
 void spectool_widget_context_channels(gpointer *aux);
 void spectool_widget_context_dbm(gpointer *aux);
 void spectool_widget_context_dbmlines(gpointer *aux);
 
 /* Color space conversion tools */
-inline void rgb_to_hsv(double r, double g, double b, 
+void rgb_to_hsv(double r, double g, double b, 
 					   double *h, double *s, double *v);
-inline void hsv_to_rgb(double *r, double *g, double *b, 
+void hsv_to_rgb(double *r, double *g, double *b, 
 					   double h, double s, double v);
 
 G_END_DECLS
