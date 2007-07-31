--- src/Thumbview.cc.orig	Tue Jan 30 04:01:36 2007
+++ src/Thumbview.cc	Wed Jul  4 17:10:44 2007
@@ -56,6 +56,11 @@
  * Constructor, sets up gtk stuff, inits data and queues
  */
 Thumbview::Thumbview() : dir("") {
+	Glib::RefPtr<Gtk::IconTheme> icontheme = Gtk::IconTheme::get_default();
+	Glib::RefPtr<Gtk::IconTheme> gnomeicontheme = Gtk::IconTheme::create();
+
+	gnomeicontheme->set_custom_theme("gnome");
+
 	set_policy (Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
 	set_shadow_type (Gtk::SHADOW_IN);
 
@@ -96,7 +101,11 @@
 	// store->set_sort_column (short_filename, Gtk::SORT_ASCENDING);
 
 	// load loading image
-	this->loading_image = Gtk::IconTheme::get_default()->load_icon("image-loading", 64, Gtk::ICON_LOOKUP_FORCE_SVG);
+	try {
+		this->loading_image = icontheme->load_icon("image-loading", 64, Gtk::ICON_LOOKUP_FORCE_SVG);
+	} catch (...) {
+		this->loading_image = gnomeicontheme->load_icon("image-loading", 64, Gtk::ICON_LOOKUP_FORCE_SVG);
+	}
 
 	// make our async queues
 	this->aqueue_createthumbs = g_async_queue_new();
