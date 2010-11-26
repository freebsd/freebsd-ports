--- gtk/gtkbuilderparser.c.dist	2010-06-08 14:11:06.000000000 -0500
+++ gtk/gtkbuilderparser.c	2010-06-08 14:11:33.000000000 -0500
@@ -1051,7 +1051,7 @@
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext *context,
+XXXtext (GMarkupParseContext *context,
       const gchar         *text,
       gsize                text_len,
       gpointer             user_data,
@@ -1106,7 +1106,7 @@
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
   NULL
 };
