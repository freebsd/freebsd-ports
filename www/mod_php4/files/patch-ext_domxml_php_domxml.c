===================================================================
RCS file: /repository/php4/ext/domxml/php_domxml.c,v
retrieving revision 1.67.2.9
retrieving revision 1.90
diff -p --unified=3 -r1.67.2.9 -r1.90
--- ext/domxml/php_domxml.c	2001/12/14 10:45:46	1.67.2.9
+++ ext/domxml/php_domxml.c	2001/12/20 14:40:43	1.90
@@ -16,7 +16,7 @@
    +----------------------------------------------------------------------+
  */

-/* $Id: php_domxml.c,v 1.67.2.9 2001/12/14 10:45:46 mfischer Exp $ */
+/* $Id: php_domxml.c,v 1.90 2001/12/20 14:40:43 mfischer Exp $ */


 #ifdef HAVE_CONFIG_H
@@ -411,9 +411,14 @@ static inline void node_list_wrapper_dto
 {
 	while (node != NULL) {
 		node_list_wrapper_dtor(node->children);
-		// FIXME temporary fix; think of something better
-		if (node->type != XML_ATTRIBUTE_DECL && node->type != XML_DTD_NODE) {
-			attr_list_wrapper_dtor(node->properties);
+		switch (node->type) {
+			/* Skip property freeing for the following types */
+			case XML_ATTRIBUTE_DECL:
+			case XML_DTD_NODE:
+			case XML_ENTITY_DECL:
+				break;
+			default:
+				attr_list_wrapper_dtor(node->properties);
 		}
 		node_wrapper_dtor(node);
 		node = node->next;
@@ -817,7 +822,6 @@ static zval *php_domobject_new(xmlNodePt
 			xmlNodePtr nodep = obj;
 			object_init_ex(wrapper, domxmlentityref_class_entry);
 			rsrc_type = le_domxmlentityrefp;
-			content = xmlNodeGetContent(nodep);
 			add_property_stringl(wrapper, "name", (char *) nodep->name, strlen(nodep->name), 1);
 			break;
 		}
@@ -932,12 +936,12 @@ PHP_MINIT_FUNCTION(domxml)
 	le_domxmlelementp =	zend_register_list_destructors_ex(php_free_xml_node, NULL, "domelement", module_number);
 	le_domxmldtdp = zend_register_list_destructors_ex(php_free_xml_node, NULL, "domdtd", module_number);
 	le_domxmlcdatap = zend_register_list_destructors_ex(php_free_xml_node, NULL, "domcdata", module_number);
+	le_domxmlentityrefp = zend_register_list_destructors_ex(php_free_xml_node, NULL, "domentityref", module_number);

 	/* Not yet initialized le_*s */
 	le_domxmldoctypep   = -10000;
 	le_domxmlpip        = -10002;
 	le_domxmlnotationp  = -10003;
-	le_domxmlentityrefp = -10004;

 #if defined(LIBXML_XPATH_ENABLED)
 	le_xpathctxp = zend_register_list_destructors_ex(php_free_xpath_context, NULL, "xpathcontext", module_number);
@@ -1586,11 +1590,7 @@ PHP_FUNCTION(domxml_node_unlink_node)
 	zval *id;
 	xmlNode *nodep;

-	DOMXML_NO_ARGS();
-
-	DOMXML_GET_THIS_OBJ(nodep, id, le_domxmlnodep);
-
-	DOMXML_NO_ARGS();
+	DOMXML_PARAM_NONE(nodep, id, le_domxmlnodep);

 	xmlUnlinkNode(nodep);
 	xmlFreeNode(nodep);
