--- gtk/gtkmm/scrolledwindow.cc.orig	Sun Jan 14 15:16:30 2007
+++ gtk/gtkmm/scrolledwindow.cc	Sun Jan 14 15:16:33 2007
@@ -166,7 +166,7 @@ void ScrolledWindow_Class::class_init_fu
 }
 
 
-void ScrolledWindow_Class::scroll_child_callback(GtkScrolledWindow* self, GtkScrollType p0, gboolean p1)
+gboolean ScrolledWindow_Class::scroll_child_callback(GtkScrolledWindow* self, GtkScrollType p0, gboolean p1)
 {
   CppObjectType *const obj = dynamic_cast<CppObjectType*>(
       Glib::ObjectBase::_get_current_wrapper((GObject*)self));
@@ -200,6 +200,9 @@ void ScrolledWindow_Class::scroll_child_
     if(base && base->scroll_child)
       (*base->scroll_child)(self, p0, p1);
   }
+
+  typedef gboolean RType;
+  return RType();
 }
 
 void ScrolledWindow_Class::move_focus_out_callback(GtkScrolledWindow* self, GtkDirectionType p0)
