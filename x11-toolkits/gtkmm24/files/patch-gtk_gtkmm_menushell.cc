--- gtk/gtkmm/menushell.cc.orig	2017-04-02 16:29:30 UTC
+++ gtk/gtkmm/menushell.cc
@@ -130,7 +130,7 @@ MenuList::iterator MenuList::insert(MenuList::iterator
 {
   const Glib::RefPtr<Gtk::MenuItem> item = element.get_child();
 
-  g_return_val_if_fail(item != 0, position);
+  g_return_val_if_fail(item, position);
   g_return_val_if_fail(gparent() != 0, position);
 
   int pos = -1;
