--- gtk/gtkmm/notebook.cc.orig	Sun Jan 14 15:16:24 2007
+++ gtk/gtkmm/notebook.cc	Sun Jan 14 15:16:33 2007
@@ -796,7 +796,7 @@ gboolean Notebook_Class::focus_tab_callb
   return RType();
 }
 
-void Notebook_Class::change_current_page_callback(GtkNotebook* self, gint p0)
+gboolean Notebook_Class::change_current_page_callback(GtkNotebook* self, gint p0)
 {
   CppObjectType *const obj = dynamic_cast<CppObjectType*>(
       Glib::ObjectBase::_get_current_wrapper((GObject*)self));
@@ -829,6 +829,9 @@ void Notebook_Class::change_current_page
     if(base && base->change_current_page)
       (*base->change_current_page)(self, p0);
   }
+
+  typedef gboolean RType;
+  return RType();
 }
 
 void Notebook_Class::move_focus_out_callback(GtkNotebook* self, GtkDirectionType p0)
