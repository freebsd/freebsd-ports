--- bakery/App/App_WithDoc.h.orig	Wed Aug 18 15:44:34 2004
+++ bakery/App/App_WithDoc.h	Wed Aug 18 15:45:06 2004
@@ -90,7 +90,7 @@
   static void session_save_document_history();
 
   //Signal handlers:
-
+public:
   //Menu items:
   virtual void on_menu_file_open();
   virtual void on_menu_file_open_recent(guint index); //use with SigC::bind.
@@ -102,7 +102,8 @@
   virtual void on_menu_edit_copy();
   virtual void on_menu_edit_paste();
   virtual void on_menu_edit_clear();
-  
+
+protected:  
   //Document:
   ///Update visual status.
   virtual void on_document_modified();
