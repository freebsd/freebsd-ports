--- examples/iconlist/iconlist.cc.orig	2013-07-27 15:02:04.000000000 +0200
+++ examples/iconlist/iconlist.cc	2013-07-27 15:02:40.000000000 +0200
@@ -58,6 +58,7 @@
     show_all_children ();
 }
  
+int
 main (int argc, char *argv[])
 {
    Gnome::Main kit ("Iconlist", "0.0.0", Gnome::UI::module_info_get(), argc, argv);
