--- gtk/gtkbuilderparser.c.orig	2023-05-22 02:22:08 UTC
+++ gtk/gtkbuilderparser.c
@@ -1149,7 +1149,7 @@ static void
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext  *context,
+XXXtext (GMarkupParseContext  *context,
       const gchar          *text,
       gsize                 text_len,
       gpointer              user_data,
@@ -1207,7 +1207,7 @@ static const GMarkupParser parser = {
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
 };
 
