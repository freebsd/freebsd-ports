--- inti/gtk/itemfactory.h.orig	Sat Sep 18 21:25:05 2004
+++ inti/gtk/itemfactory.h	Sat Sep 18 21:26:59 2004
@@ -373,7 +373,7 @@
 		int i = 0;
 		while ((owner.item_factory_map[i]).path)
 		{
-			delete_entry(item_factory_map[i]);
+			delete_entry(owner.item_factory_map[i]);
 			i++;
 		}
 	}
