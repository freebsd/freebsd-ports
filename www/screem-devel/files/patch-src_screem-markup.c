--- src/screem-markup.c.orig	Wed Nov 13 08:19:22 2002
+++ src/screem-markup.c	Sun Dec  1 21:57:23 2002
@@ -778,7 +778,7 @@
 
 GSList *screem_markup_get_links( ScreemDTD *dtd, const gchar *text )
 {
-	GSList *ret;
+	GSList *ret, *attr, *tmp;
 	gchar *next;
 	gint pos;
 	gint end;
@@ -792,8 +792,8 @@
 						NULL, &end, &name ) ) ) {
 		pos = end;
 		/* get tag attributes */
-		GSList *attr;
-		GSList *tmp;
+		/* GSList *attr; */
+		/* GSList *tmp; */
 
 		attr = screem_markup_build_attributes_list( next, NULL );
 
