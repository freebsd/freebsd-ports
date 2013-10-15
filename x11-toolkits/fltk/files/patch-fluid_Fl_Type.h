--- fluid/Fl_Type.h.orig	2013-10-15 09:58:05.000000000 +0200
+++ fluid/Fl_Type.h	2013-10-15 10:01:26.000000000 +0200
@@ -33,10 +33,12 @@
 
 void set_modflag(int mf);
 
+Fl_Widget *make_type_browser(int,int,int,int,const char *l=0);
+
 class Fl_Type {
 
   friend class Widget_Browser;
-  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l=0);
+  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l);
   friend class Fl_Window_Type;
   virtual void setlabel(const char *); // virtual part of label(char*)
 
