
$FreeBSD$

--- src/gnome--/app.cc	2002/07/16 10:16:49	1.1
+++ src/gnome--/app.cc	2002/07/16 10:18:08
@@ -162,13 +162,13 @@
     return w;
   }
 
-App::Progress App::progress(const Gtk::string &description, Callback cancel=0)
+App::Progress App::progress(const Gtk::string &description, Callback cancel)
   {
     return Progress(*this,  description, cancel);
   }
 
 App::Progress App::progress(const Gtk::string &description, guint32 interval,
-                    ProgressCallback percent, Callback cancel=0)
+                    ProgressCallback percent, Callback cancel)
   {
     return Progress(*this,  description, interval, percent, cancel);
   }
@@ -210,7 +210,7 @@
 
 Progress::Progress(Gnome::App& app,
                    const Gtk::string &description,
-                   Cancel cancel=0)
+                   Cancel cancel)
   {
     ProgressCallbackData *data=new ProgressCallbackData();
     data->cancel=cancel;
@@ -225,7 +225,7 @@
                    const Gtk::string &description,
                    guint32 interval,
                    Update percent,
-                   Cancel cancel=0)
+                   Cancel cancel)
   {
     ProgressCallbackData *data=new ProgressCallbackData();
     data->cancel=cancel;
