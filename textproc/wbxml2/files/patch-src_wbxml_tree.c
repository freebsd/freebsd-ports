--- src/wbxml_tree.c.orig	2006-07-11 21:47:45.000000000 +1000
+++ src/wbxml_tree.c	2008-06-15 06:59:31.000000000 +1000
@@ -137,6 +137,7 @@
 
         /* Use String Table */
         wbxml_encoder_set_use_strtbl(wbxml_encoder, TRUE);
+        wbxml_encoder_set_produce_anonymous(wbxml_encoder, FALSE);
     }
     else {
         /* WBXML Version */
@@ -153,6 +156,7 @@
 
         /* String Table */
         wbxml_encoder_set_use_strtbl(wbxml_encoder, params->use_strtbl);
+        wbxml_encoder_set_produce_anonymous(wbxml_encoder, params->produce_anonymous);
 
         /** @todo Add parameter to call : wbxml_encoder_set_output_charset() */
     }
@@ -256,7 +262,8 @@
 
 #else /* HAVE_EXPAT */
 
-#if defined( HAVE_LIBXML )
+//#if defined( HAVE_LIBXML )
+#if 0
 
     /** @todo Use LibXML2 SAX interface ! */
     return WBXML_ERROR_NO_XMLPARSER;
@@ -333,7 +340,8 @@
 }
 
 
-#if defined( HAVE_LIBXML )
+// #if defined( HAVE_LIBXML )
+#if 0
 
 WBXML_DECLARE(WBXMLError) wbxml_tree_from_libxml_doc(xmlDocPtr libxml_doc,
                                                      WBXMLTree **tree)
@@ -617,6 +625,40 @@
 }
 
 
+WBXML_DECLARE(WBXMLError) wbxml_tree_node_extract(WBXMLTreeNode *node)
+{
+    if (node == NULL)
+        return WBXML_ERROR_BAD_PARAMETER;
+    
+    /* Parent link */
+    if (node->parent != NULL) {
+        if (node->parent->children == node) {
+            /* Update parent children */
+		    node->parent->children = node->next;
+        }
+
+        /* No more parent */
+        node->parent = NULL;
+    }
+
+    /* Next link */
+    if (node->next != NULL) {
+        /* Link next node to previous node */
+        node->next->prev = node->prev;
+        node->next = NULL;
+    }
+
+    /* Previous link */
+    if (node->prev != NULL) {
+        /* Link previous node to next node */
+        node->prev->next = node->next;
+        node->prev = NULL;
+    }
+    
+    return WBXML_OK;
+}
+
+
 WBXML_DECLARE(WBXMLError) wbxml_tree_node_add_attr(WBXMLTreeNode *node,
                                                    WBXMLAttribute *attr)
 {
@@ -938,34 +982,17 @@
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WB_BOOL) wbxml_tree_add_node(WBXMLTree *tree, WBXMLTreeNode *parent, WBXMLTreeNode *node)
 {
     WBXMLTreeNode *tmp = NULL;
 
     if ((tree == NULL) || (node == NULL))
         return FALSE;
-
-    /* Set parent to new node */
-    node->parent = parent;    
-
+    
     /* Check if this is the Root Element */
     if (parent != NULL) {
-        /* This is not the Root Element... search for previous sibbling element */
-        if (parent->children != NULL) {
-            /* Add this Node to end of Sibbling Node list of Parent */
-            tmp = parent->children;
-
-            while (tmp->next != NULL)
-                tmp = tmp->next;
-            
-            node->prev = tmp;
-            tmp->next = node;
-        }
-        else {
-            /* No previous sibbling element */
-            parent->children = node;
-        }
+        if (!wbxml_tree_node_add_child(parent, node))
+            return FALSE;
     }
     else {
         /* We do NOT allow replacement of an existing Tree Node */
@@ -974,53 +1001,28 @@
 
         /* This is the Root Element */
         tree->root = node;
+        node->parent = NULL;
     }
 
     return TRUE;
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLError) wbxml_tree_extract_node(WBXMLTree *tree,
                                                   WBXMLTreeNode *node)
 {
     if ((tree == NULL) || (node == NULL))
         return WBXML_ERROR_BAD_PARAMETER;
-
-    /* Parent link */
-    if (node->parent != NULL) {
-        if (node->parent->children == node) {
-            /* Update parent children */
-		    node->parent->children = node->next;
-        }
-
-        /* No more parent */
-        node->parent = NULL;
-    }
-    else {
+    
+    if (node == tree->root) {
         /* Root removed ! */
         tree->root = node->next;
     }
 
-    /* Next link */
-    if (node->next != NULL) {
-        /* Link next node to previous node */
-        node->next->prev = node->prev;
-        node->next = NULL;
-    }
-
-    /* Previous link */
-    if (node->prev != NULL) {
-        /* Link previous node to next node */
-        node->prev->next = node->next;
-        node->prev = NULL;
-    }
-
-    return WBXML_OK;
+    return wbxml_tree_node_extract(node);
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLTreeNode *) wbxml_tree_add_elt(WBXMLTree *tree,
                                                   WBXMLTreeNode *parent,
                                                   WBXMLTag *tag)
@@ -1048,7 +1050,6 @@
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLTreeNode *) wbxml_tree_add_elt_with_attrs(WBXMLTree *tree,
                                                              WBXMLTreeNode *parent,
                                                              WBXMLTag *tag,
@@ -1075,36 +1076,15 @@
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLTreeNode *) wbxml_tree_add_xml_elt(WBXMLTree *tree,
                                                       WBXMLTreeNode *parent,
                                                       WB_UTINY *name)
 {
-    const WBXMLTagEntry *tag_entry = NULL;
     WBXMLTreeNode *node = NULL;
-    WBXMLTag *tag = NULL;
     
-    /* Search for XML Tag Name in Table */
-    if ((tag_entry = wbxml_tables_get_tag_from_xml(tree->lang, (const WB_UTINY *) name)) != NULL) {
-        /* Found : token tag */
-        tag = wbxml_tag_create_token(tag_entry);
-    }
-    else {
-        /* Not found : literal tag */
-        tag = wbxml_tag_create_literal(name);
-    }
-
-    if (tag == NULL)
-        return NULL;
-
-    /* Create a new Node */
-    if ((node = wbxml_tree_node_create(WBXML_TREE_ELEMENT_NODE)) == NULL) {
-        wbxml_tag_destroy(tag);
+    /* Create element node */
+    if ((node = wbxml_tree_node_create_xml_elt(tree->lang, (const WB_UTINY *) name)) == NULL)
         return NULL;
-    }
-    
-    /* Set Node Tag */
-    node->name = tag;
 
     /* Add this Node to Tree  */
     if (!wbxml_tree_add_node(tree, parent, node)) {
@@ -1116,7 +1096,6 @@
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLTreeNode *) wbxml_tree_add_xml_elt_with_attrs(WBXMLTree *tree,
                                                                  WBXMLTreeNode *parent,
                                                                  WB_UTINY *name,
@@ -1143,7 +1122,6 @@
 }
 
 
-/** @todo Rewrite this function (use wbxml_tree_node_* functions) */
 WBXML_DECLARE(WBXMLTreeNode *) wbxml_tree_add_text(WBXMLTree *tree,
                                                    WBXMLTreeNode *parent,
                                                    const WB_UTINY *text,
@@ -1152,13 +1130,7 @@
     WBXMLTreeNode *node = NULL;
 
     /* Create a new Node */
-    if ((node = wbxml_tree_node_create(WBXML_TREE_TEXT_NODE)) == NULL) {
-        return NULL;
-    }
-
-    /* Set Content */
-    if ((node->content = wbxml_buffer_create(text, len, len)) == NULL) {
-        wbxml_tree_node_destroy(node);
+    if ((node = wbxml_tree_node_create_text(text, len)) == NULL) {
         return NULL;
     }
 
