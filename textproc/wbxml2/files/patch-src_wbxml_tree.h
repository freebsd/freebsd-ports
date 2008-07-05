--- src/wbxml_tree.h.orig	2008-06-15 08:10:30.000000000 +1000
+++ src/wbxml_tree.h	2008-06-15 08:11:09.000000000 +1000
@@ -308,6 +308,7 @@
 WBXML_DECLARE(WB_BOOL) wbxml_tree_node_add_child(WBXMLTreeNode *parent,
                                                  WBXMLTreeNode *node);
 
+WBXML_DECLARE(WBXMLError) wbxml_tree_node_extract(WBXMLTreeNode *node);
 /**
  * @brief Add a WBXML Attribute to a Tree Node structure
  * @param node The Tree Node to modify
