
$FreeBSD$

--- src/gnome--/clock.cc	2002/07/16 10:27:15	1.1
+++ src/gnome--/clock.cc	2002/07/16 10:27:28
@@ -5,7 +5,7 @@
 #include <gnome--/private/clock_p.h>
 #include <gnome--/construct_copies.h>
 
-Gtk::Clock::Clock(Type type = REALTIME)
+Gtk::Clock::Clock(Type type)
   : Gtk::Label(GTK_LABEL(gtk_object_new(get_type(),0)))
 {
   initialize_class();
