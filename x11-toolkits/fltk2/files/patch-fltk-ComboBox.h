--- fltk/ComboBox.h.orig	Sun Apr  2 12:05:31 2006
+++ fltk/ComboBox.h	Sun Apr  2 12:07:16 2006
@@ -103,7 +103,7 @@
 	ComboBox *combo_;
   };  
   ComboInput *input_;
-#ifdef _WIN32
+#if defined ( _WIN32 ) || defined ( __GNUC__ ) && __GNUC__ < 3
  public:
 #endif
   static void input_callback_(Widget*,void*);
