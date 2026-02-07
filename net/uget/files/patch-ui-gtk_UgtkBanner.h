--- ui-gtk/UgtkBanner.h.orig	2018-01-08 00:04:26 UTC
+++ ui-gtk/UgtkBanner.h
@@ -49,7 +49,7 @@ typedef struct UgtkBanner    UgtkBanner;
 
 // --------------------------------
 // Banner
-struct UgtkBanner {
+extern struct UgtkBanner {
 	GtkWidget*      self;
 	GtkTextView*    text_view;
 	GtkTextBuffer*  buffer;
