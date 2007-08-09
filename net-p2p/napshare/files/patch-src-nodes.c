--- src/nodes.c.orig	2007-08-09 19:34:29.000000000 +0200
+++ src/nodes.c	2007-08-09 19:38:23.000000000 +0200
@@ -386,7 +386,7 @@
 			}
 
 			if(r && n->end_of_packets)
-			  (guint32) n->end_of_packets->data -= r;
+			  n->end_of_packets->data -= r;
 
 			gui_update_node(n, FALSE);
 
