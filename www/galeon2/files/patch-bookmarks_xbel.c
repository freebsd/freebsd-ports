--- bookmarks/xbel.c.orig	Tue Oct 28 00:27:13 2003
+++ bookmarks/xbel.c	Tue Oct 28 00:27:28 2003
@@ -1065,7 +1065,7 @@
 xbel_save_galeon_metadata_remove_metadata (xmlNodePtr node)
 {
         xmlNodePtr infoNode;
-        xmlNodePtr metaNode;;
+        xmlNodePtr metaNode;
 	xmlNodePtr first_info = NULL;
 	xmlNodePtr found = NULL;
 	
