--- src/NWindow.cc.orig	Sat May 12 05:12:25 2007
+++ src/NWindow.cc	Wed Jul  4 17:07:08 2007
@@ -155,9 +155,16 @@
 void NWindow::setup_select_boxes() {
 		
 	Glib::RefPtr<Gtk::IconTheme> icontheme = Gtk::IconTheme::get_default();
+	Glib::RefPtr<Gtk::IconTheme> gnomeicontheme = Gtk::IconTheme::create();
 	Glib::RefPtr<Gdk::Pixbuf> icon, genericicon;
 
-	genericicon = icontheme->load_icon("image-x-generic", 16, Gtk::ICON_LOOKUP_NO_SVG);
+	gnomeicontheme->set_custom_theme("gnome");
+
+	try {
+		genericicon = icontheme->load_icon("image-x-generic", 16, Gtk::ICON_LOOKUP_NO_SVG);
+	} catch (...) {
+		genericicon = gnomeicontheme->load_icon("image-x-generic", 16, Gtk::ICON_LOOKUP_NO_SVG);
+	}
 
 	// modes
 	try {
