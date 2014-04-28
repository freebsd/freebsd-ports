--- src/fl_sources/json_api_mapper.c.orig	2014-04-11 22:59:09.000000000 +0200
+++ src/fl_sources/json_api_mapper.c	2014-04-11 23:00:05.000000000 +0200
@@ -55,7 +55,7 @@
 	const gchar	*field;
 
 	if (!node || !mapping)
-		return;
+		return NULL;
 
 	node = json_api_get_node (parent, mapping);
 	field = strrchr (mapping, '/');
@@ -74,7 +74,7 @@
 	const gchar	*field;
 
 	if (!node || !mapping)
-		return;
+		return NULL;
 
 	node = json_api_get_node (parent, mapping);
 	field = strrchr (mapping, '/');
@@ -93,7 +93,7 @@
 	const gchar	*field;
 
 	if (!node || !mapping)
-		return;
+		return NULL;
 
 	node = json_api_get_node (parent, mapping);
 	field = strrchr (mapping, '/');
