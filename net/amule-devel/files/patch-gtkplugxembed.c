--- src/gtkplugxembed.c.orig	Sat Oct 23 05:57:50 2004
+++ src/gtkplugxembed.c	Sat Oct 23 06:01:38 2004
@@ -889,7 +889,7 @@
 static void
 focus_first_last (GtkPlugXEmbed          *plug,
 		  GtkDirectionType  direction)
-{ (void)direction;
+{
   GtkWindow *window = GTK_WINDOW (plug);
   GtkWidget *parent;
   
@@ -1045,7 +1045,7 @@
 
 static GdkFilterReturn
 gtk_plug_xembed_filter_func (GdkXEvent *gdk_xevent, GdkEvent *event, gpointer data)
-{ (void)event;
+{
   GtkPlugXEmbed *plug = GTK_PLUG_XEMBED (data);
   XEvent *xevent = (XEvent *)gdk_xevent;
 
