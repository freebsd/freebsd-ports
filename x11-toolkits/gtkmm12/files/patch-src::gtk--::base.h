--- src/gtk--/base.h.orig	Tue Nov 14 21:23:11 2000
+++ src/gtk--/base.h	Sun Sep  5 06:11:48 2004
@@ -454,6 +454,13 @@
   pointer operator -> () const { return &operator*(); }
 };
 
+namespace Gtk {
+
+template <class impl, class interf>
+interf* wrap(impl*);
+
+}
+
 // this iterator variation returns interf (wrapped from impl)
 //  Equivelency  G_List_Cpp_Iterator<GtkWidget,Gtk_Widget>
 //     => list<Gtk_Widget*>::iterator
@@ -482,7 +489,7 @@
   value_type operator*() const
   {
     if (node && node->data)
-      return Gtk::wrap(static_cast<impl*>((*node).data));
+      return Gtk::wrap<impl, interf>(static_cast<impl*>((*node).data));
     return 0;
   }
 
