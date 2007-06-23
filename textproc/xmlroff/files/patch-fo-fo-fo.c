--- fo/fo-fo.c.orig	Sat Aug 19 01:29:53 2006
+++ fo/fo-fo.c	Sat Aug 19 01:30:44 2006
@@ -1213,6 +1213,8 @@
   while (iterator)
     {
       FoProperty *property = NULL;
+      FoPropertyClass *property_class = NULL;
+      FoTypeFunc type_func;
 
       /* Skip processing attributes that have already been handled. */
       if (strcmp (xslAttrListIteratorName (iterator), "font-size") == 0 ||
@@ -1234,8 +1236,8 @@
 	    }
 	}
 
-      FoPropertyClass *property_class = NULL;
-      FoTypeFunc type_func =
+      property_class = NULL;
+      type_func =
 	g_hash_table_lookup (prop_eval_hash,
 			     xslAttrListIteratorName (iterator));
 
