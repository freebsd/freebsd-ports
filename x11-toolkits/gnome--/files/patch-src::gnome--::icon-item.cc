
$FreeBSD$

--- src/gnome--/icon-item.cc	2002/07/16 10:42:28	1.1
+++ src/gnome--/icon-item.cc	2002/07/16 10:42:56
@@ -27,7 +27,7 @@
 void Gnome::IconTextItem::configure(int x, int y, int width,
 			      const Gtk::string &fontname,
 			      const Gtk::string &text,
-			      bool is_editable = true)
+			      bool is_editable)
 {
   gnome_icon_text_item_configure(gtkobj(), x, y, width,
                                  fontname.c_str(), text.c_str(),
