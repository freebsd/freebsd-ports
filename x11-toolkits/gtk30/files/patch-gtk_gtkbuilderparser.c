--- gtk/gtkbuilderparser.c.orig	2015-11-12 16:34:36.000000000 +0100
+++ gtk/gtkbuilderparser.c	2015-11-12 23:17:26.500037000 +0100
@@ -1146,7 +1146,7 @@
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext  *context,
+XXXtext (GMarkupParseContext  *context,
       const gchar          *text,
       gsize                 text_len,
       gpointer              user_data,
@@ -1204,7 +1204,7 @@
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
 };
 
