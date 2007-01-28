--- efltk/Fl_Combo_Box.h.orig	Sun Jan 28 17:54:29 2007
+++ efltk/Fl_Combo_Box.h	Sun Jan 28 17:54:45 2007
@@ -23,8 +23,8 @@
 
     void ctor_init();
 protected:
-    static void Fl_Combo_Box::cb_browse(Fl_Widget *w, void *data);
-    static void Fl_Combo_Box::cb_button(Fl_Widget *w, void *data);
+    static void cb_browse(Fl_Widget *w, void *data);
+    static void cb_button(Fl_Widget *w, void *data);
 public:
     static Fl_Named_Style* default_style;
 
