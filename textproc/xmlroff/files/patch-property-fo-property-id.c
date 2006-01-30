--- property/fo-property-id.c.orig	Mon Jan 30 23:46:23 2006
+++ property/fo-property-id.c	Mon Jan 30 23:46:44 2006
@@ -262,10 +262,11 @@
 {
   static int count = 1;
   FoProperty *id;
+  gchar *id_string = NULL;
 
   id = fo_property_id_new ();
 
-  gchar * id_string = g_strdup_printf ("id-%d",
+  id_string = g_strdup_printf ("id-%d",
 				       count++);
   /* Set the initial value here */
   fo_property_set_value (id,
