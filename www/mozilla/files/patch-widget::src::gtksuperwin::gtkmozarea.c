Patch that fixes a bug with Galeon. Should go after 0.9. Obtained from
http://bugzilla.mozilla.org/show_bug.cgi?id=79022.

$FreeBSD$

--- widget/src/gtksuperwin/gtkmozarea.c.orig	Thu May  3 07:11:01 2001
+++ widget/src/gtksuperwin/gtkmozarea.c	Tue May 22 13:46:58 2001
@@ -25,6 +25,7 @@
 static void gtk_mozarea_unrealize  (GtkWidget       *widget);
 static void gtk_mozarea_size_allocate (GtkWidget    *widget,
                                        GtkAllocation *allocation);
+static void gtk_mozarea_destroy    (GtkObject       *object);
 
 static void
 attach_toplevel_listener(GtkMozArea *mozarea);
@@ -85,6 +86,8 @@
   widget_class->unrealize = gtk_mozarea_unrealize;
   widget_class->size_allocate = gtk_mozarea_size_allocate;
 
+  object_class->destroy = gtk_mozarea_destroy;
+
   parent_class = gtk_type_class(gtk_widget_get_type());
 
   /* set up our signals */
@@ -112,6 +115,7 @@
 {
   mozarea->superwin = NULL;
   mozarea->toplevel_focus = FALSE;
+  mozarea->toplevel_window = NULL;
 }
 
 static void 
@@ -179,6 +183,22 @@
     }
 }
 
+static void
+gtk_mozarea_destroy(GtkObject *object)
+{
+  GtkMozArea *mozarea;
+
+  g_return_if_fail(GTK_IS_MOZAREA(object));
+  
+  mozarea = GTK_MOZAREA(object);
+
+  /* remove the filter on the toplevel window */
+  gdk_window_remove_filter(mozarea->toplevel_window, toplevel_window_filter,
+                           mozarea);
+
+  GTK_OBJECT_CLASS(parent_class)->destroy(object);
+}
+
 GtkWidget*
 gtk_mozarea_new (GdkWindow *parent_window)
 {
@@ -220,6 +240,10 @@
      automatically be removed. */
 
   gdk_window_add_filter(gdk_window, toplevel_window_filter, mozarea);
+
+  /* save it so that we can remove the filter later */
+
+  mozarea->toplevel_window = gdk_window;
 }
 
 /* this function will try to find the real toplevel for a gdk window. */
