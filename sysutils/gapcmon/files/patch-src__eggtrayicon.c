--- src/eggtrayicon.c.orig	Fri May 12 10:54:17 2006
+++ src/eggtrayicon.c	Mon Jan  1 12:46:03 2007
@@ -61,6 +61,9 @@
 static void egg_tray_icon_realize(GtkWidget * widget);
 static void egg_tray_icon_unrealize(GtkWidget * widget);
 
+static void egg_tray_icon_add (GtkContainer *container,
+			       GtkWidget    *widget);
+
 static void egg_tray_icon_update_manager_window(EggTrayIcon * icon,
    gboolean dock_if_realized);
 static void egg_tray_icon_manager_window_destroyed(EggTrayIcon * icon);
@@ -101,6 +104,7 @@
 {
    GObjectClass *gobject_class = (GObjectClass *) klass;
    GtkWidgetClass *widget_class = (GtkWidgetClass *) klass;
+   GtkContainerClass *container_class = (GtkContainerClass *)klass;
 
    parent_class = g_type_class_peek_parent(klass);
 
@@ -109,6 +113,8 @@
    widget_class->realize = egg_tray_icon_realize;
    widget_class->unrealize = egg_tray_icon_unrealize;
 
+   container_class->add = egg_tray_icon_add;
+
    g_object_class_install_property(gobject_class,
       PROP_ORIENTATION,
       g_param_spec_enum("orientation",
@@ -298,6 +304,36 @@
    }
 }
 
+static gboolean
+transparent_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
+{
+  gdk_window_clear_area (widget->window, event->area.x, event->area.y,
+			 event->area.width, event->area.height);
+  return FALSE;
+}
+
+static void
+make_transparent_again (GtkWidget *widget, GtkStyle *previous_style,
+			gpointer user_data)
+{
+  gdk_window_set_back_pixmap (widget->window, NULL, TRUE);
+}
+
+static void
+make_transparent (GtkWidget *widget, gpointer user_data)
+{
+  if (GTK_WIDGET_NO_WINDOW (widget) || GTK_WIDGET_APP_PAINTABLE (widget))
+    return;
+
+  gtk_widget_set_app_paintable (widget, TRUE);
+  gtk_widget_set_double_buffered (widget, FALSE);
+  gdk_window_set_back_pixmap (widget->window, NULL, TRUE);
+  g_signal_connect (widget, "expose_event",
+		    G_CALLBACK (transparent_expose_event), NULL);
+  g_signal_connect_after (widget, "style_set",
+			  G_CALLBACK (make_transparent_again), NULL);
+}	
+
 static void egg_tray_icon_manager_window_destroyed(EggTrayIcon * icon)
 {
    GdkWindow *gdkwin;
@@ -327,6 +363,8 @@
    if (GTK_WIDGET_CLASS(parent_class)->realize)
       GTK_WIDGET_CLASS(parent_class)->realize(widget);
 
+   make_transparent (widget, NULL);
+
    screen = gtk_widget_get_screen(widget);
    display = gdk_screen_get_display(screen);
    xdisplay = gdk_x11_display_get_xdisplay(display);
@@ -352,6 +390,14 @@
 
    /* Add a root window filter so that we get changes on MANAGER */
    gdk_window_add_filter(root_window, egg_tray_icon_manager_filter, icon);
+}
+
+static void
+egg_tray_icon_add (GtkContainer *container, GtkWidget *widget)
+{
+  g_signal_connect (widget, "realize",
+		    G_CALLBACK (make_transparent), NULL);
+  GTK_CONTAINER_CLASS (parent_class)->add (container, widget);
 }
 
 EggTrayIcon *egg_tray_icon_new_for_screen(GdkScreen * screen, const char *name)
