--- result-to-fo.c.orig	Mon Jan 10 14:56:38 2005
+++ result-to-fo.c	Mon Jan 10 14:57:14 2005
@@ -852,6 +852,8 @@
   while (iterator)
     {
       FoProperty *property = NULL;
+      FoPropertyClass *property_class = NULL;
+      FoTypeFunc type_func;
 
       if (strcmp (xslAttrListIteratorName (iterator), "font-size") == 0 ||
 	  (FO_IS_TABLE_CELL (fo_fo) &&
@@ -872,8 +874,8 @@
 	    }
 	}
 
-      FoPropertyClass *property_class = NULL;
-      FoTypeFunc type_func =
+      property_class = NULL;
+      type_func =
 	g_hash_table_lookup (prop_eval_hash,
 			     xslAttrListIteratorName (iterator));
 
