--- src/network/location.c.orig	Thu Dec 23 13:16:33 2004
+++ src/network/location.c	Thu Dec 23 13:16:40 2004
@@ -687,7 +687,7 @@
 static void
 copy_tag_list (xmlNodePtr source, xmlNodePtr dest, const gchar *list[])
 {
-  gchar **string = (gchar **) list;;
+  gchar **string = (gchar **) list;
   gchar  *value;
 
   while (*string)
