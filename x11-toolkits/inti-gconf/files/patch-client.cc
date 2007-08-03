--- inti/gconf/client.cc.orig	2007-08-03 14:48:40.000000000 +0200
+++ inti/gconf/client.cc	2007-08-03 14:49:08.000000000 +0200
@@ -147,7 +147,7 @@
 
 	while (next != 0)
 	{
-		list.push_back((int)next->data);
+		list.push_back((intptr_t)next->data);
 		next = g_slist_next(next);
 	}
 
