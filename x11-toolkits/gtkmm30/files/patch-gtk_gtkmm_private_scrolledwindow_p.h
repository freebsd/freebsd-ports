--- gtk/gtkmm/private/scrolledwindow_p.h.orig	Sun Jan 14 15:17:41 2007
+++ gtk/gtkmm/private/scrolledwindow_p.h	Sun Jan 14 15:17:46 2007
@@ -33,7 +33,7 @@ protected:
   //Callbacks (default signal handlers):
   //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
   //You could prevent the original default signal handlers being called by overriding the *_impl method.
-  static void scroll_child_callback(GtkScrolledWindow* self, GtkScrollType p0, gboolean p1);
+  static gboolean scroll_child_callback(GtkScrolledWindow* self, GtkScrollType p0, gboolean p1);
   static void move_focus_out_callback(GtkScrolledWindow* self, GtkDirectionType p0);
 
   //Callbacks (virtual functions):
