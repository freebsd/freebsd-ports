--- bakery/App/App.h.orig	Thu Jan  2 08:46:33 2003
+++ bakery/App/App.h	Wed Aug 18 15:50:32 2004
@@ -93,6 +93,7 @@
 //  virtual void bring_to_front() = 0;
   //Signal handlers:
 
+public:
   //Menus:
   virtual void on_menu_file_new();
   virtual void on_menu_file_close();
@@ -109,7 +110,7 @@
 
   virtual void on_about_close();
 
-
+protected:
   //GUI abstractions:
   virtual void ui_hide() = 0;
   virtual void ui_bring_to_front() = 0;
