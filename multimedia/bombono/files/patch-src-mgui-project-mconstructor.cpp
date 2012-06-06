--- src/mgui/project/mconstructor.cpp.orig	2012-06-05 22:41:12.000000000 +0200
+++ src/mgui/project/mconstructor.cpp	2012-06-05 22:42:17.000000000 +0200
@@ -961,7 +961,7 @@
         static const fs::directory_iterator end_itr;
         for( fs::directory_iterator itr(DataDirPath("bmd-icons"));
             itr != end_itr; ++itr )
-            pix_lst.push_back(Gdk::Pixbuf::create_from_file(itr->string()));
+            pix_lst.push_back(Gdk::Pixbuf::create_from_file(itr->path().string()));
         Gtk::Window::set_default_icon_list(pix_lst);
     
         ActionFunctor after_fnr = BuildConstructor(app, prj_file_name);
