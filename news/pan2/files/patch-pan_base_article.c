--- pan/base/article.c.orig	Sat Apr 26 00:33:54 2003
+++ pan/base/article.c	Sat Apr 26 00:45:00 2003
@@ -505,7 +505,6 @@
 	if (changed_qty > 0)
 		articles_set_dirty (changed, changed_qty);
 
-	g_free (changed);
 }
 
 
