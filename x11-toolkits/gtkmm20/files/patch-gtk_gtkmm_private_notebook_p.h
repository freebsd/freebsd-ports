--- gtk/gtkmm/private/notebook_p.h.orig	Sun Jan 14 15:17:36 2007
+++ gtk/gtkmm/private/notebook_p.h	Sun Jan 14 15:17:46 2007
@@ -36,7 +36,7 @@ protected:
   static void switch_page_callback(GtkNotebook* self, GtkNotebookPage* p0, guint p1);
   static gboolean select_page_callback(GtkNotebook* self, gboolean p0);
   static gboolean focus_tab_callback(GtkNotebook* self, GtkNotebookTab p0);
-  static void change_current_page_callback(GtkNotebook* self, gint p0);
+  static gboolean change_current_page_callback(GtkNotebook* self, gint p0);
   static void move_focus_out_callback(GtkNotebook* self, GtkDirectionType p0);
 
   //Callbacks (virtual functions):
