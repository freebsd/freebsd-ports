--- src/seahorse-generate-select.c.orig	2008-11-23 18:28:34.000000000 -0500
+++ src/seahorse-generate-select.c	2008-11-23 18:29:30.000000000 -0500
@@ -197,8 +197,10 @@ static GObject * seahorse_generate_selec
 			GList* typ_it;
 			typ_collection = types;
 			for (typ_it = typ_collection; typ_it != NULL; typ_it = typ_it->next) {
+				SeahorseRegistryType *rtype;
 				GType typ;
-				typ = GPOINTER_TO_INT (typ_it->data);
+				rtype = (SeahorseRegistryType *) typ_it->data;
+				typ = rtype->type;
 				{
 					SeahorseGenerator* generator;
 					gint _tmp5;
